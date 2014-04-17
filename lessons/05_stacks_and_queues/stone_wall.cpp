/*
 * Source: https://codility.com/demo/take-sample-test/stone_wall
 * Result: not solved yet
 *
 * Solution to this task can be found at our blog.
 *
 * You are going to build a stone wall. The wall should be straight and
 * N meters long, and its thickness should be constant; however, it
 * should have different heights in different places. The height of the
 * wall is specified by a zero-indexed array H of N positive
 * integers. H[I] is the height of the wall from I to I+1 meters to the
 * right of its left end. In particular, H[0] is the height of the wall's
 * left end and H[N−1] is the height of the wall's right end.
 *
 * The wall should be built of cuboid stone blocks (that is, all sides
 * of such blocks are rectangular). Your task is to compute the minimum
 * number of blocks needed to build the wall.
 *
 * Write a function:
 *
 *   int solution(const vector<int> &H);
 *
 * that, given a zero-indexed array H of N positive integers specifying
 * the height of the wall, returns the minimum number of blocks needed
 * to build it.
 *
 * For example, given array H containing N = 9 integers:
 *
 * H[0] = 8    H[1] = 8    H[2] = 5
 * H[3] = 7    H[4] = 9    H[5] = 8
 * H[6] = 7    H[7] = 4    H[8] = 8
 *
 * the function should return 7. The figure shows one possible
 * arrangement of seven blocks.
 *
 * Assume that:
 *
 *       N is an integer within the range [1..100,000];
 *       each element of array H is an integer within the range
 *         [1..1,000,000,000].
 *
 * Complexity:
 *
 *       expected worst-case time complexity is O(N);
 *       expected worst-case space complexity is O(N), beyond input
 *         storage (not counting the storage required for input
 *         arguments).
 *
 *Elements of input arrays can be modified.
*/

// you can also use includes, for example:
#include <queue>
#include <iostream>
using namespace std;

int solution(const vector<int> &H) {
    // write your code in C++98
    int N = H.size();
    queue<int> heights;
    int block_count = 0;
    int cur_height = H[0];

    for(int i = 1; i < N; i++) {
        cout << "iteration:\t" << i << "\t";
        //go right while the lower height is not met
        //remembering !indices! of all higher heights
        if ((H[i] > cur_height) and (i != N-1)) {
            heights.push(i);
            cout << "enqueued height:  " << H[i] <<endl;
        }
        //lower height or eond of line met
        else if (H[i] < cur_height) {
            cout << "finished block at height  " << cur_height <<endl;
            block_count++;     //finish current cascade block
            cur_height = H[i]; //new cascade block height
            cout << "started block at height  " << cur_height <<endl;
        }
        else if (i == N-1) {
            block_count++;
            heights.push(i);
            cout << "finished block at height  " << cur_height <<endl;
        }
    }

    cout << "\ncascade level block count:  " << block_count << endl;

    //cur_height = H[heights.front()];
    int cur_height_index = heights.front();
    heights.pop();
    //int next_height;
    int next_height_index;

    while (!heights.empty()) {
        // go right until we meet the height lower
        next_height_index = heights.front();
        //next_height = H[heights.front()];
        while (H[next_height_index] >= H[cur_height_index]) {
            next_height_index++;
        }

        cout << "cur height finished:\t" << H[cur_height_index] << endl;

        //found end of the block
        block_count++;
        cur_height_index = heights.front();
        heights.pop();
    }

    cout << "final block count:\t" << block_count << endl;

    return block_count;
}
