/* 

    lid: https://leetcode.com/problems/find-the-town-judge

    In a town, there are N people labelled from 1 to N. 
    There is a rumor that one of these people is secretly the town judge.

    If the town judge exists, then:
    The town judge trusts nobody.
    Everybody (except for the town judge) trusts the town judge.
    There is exactly one person that satisfies properties 1 and 2.
    You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

    If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

    Example 1:
    Input: N = 2, trust = [[1,2]]
    Output: 2
    Example 2:

    Input: N = 3, trust = [[1,3],[2,3]]
    Output: 3
    Example 3:

    Input: N = 3, trust = [[1,3],[2,3],[3,1]]
    Output: -1
    Example 4:

    Input: N = 3, trust = [[1,2],[2,3]]
    Output: -1
    Example 5:

    Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
    Output: 3
    
    Constraints:
    - 1 <= N <= 1000
    - 0 <= trust.length <= 10^4
    - trust[i].length == 2
    - trust[i] are all different
    - trust[i][0] != trust[i][1]
    - 1 <= trust[i][0], trust[i][1] <= N

*/

#include <vector>

using namespace std;

/* 

    As everybody trusts town judge and town judge trusts nobody,
    this is 0-sum game, where giving trust takes away trust points from you.
    Hence, if judge trusts even a single person, he will loose from required points(n-1)
    and won't be a judge anymore.

 */
int findJudge(int N, vector<vector<int>>& trust) {
    // for this problem mapping ith person to ith index is useful
    vector<int> people(N + 1, 0);

    for (const auto& i : trust) {
        people[i[0]] -= 1;
        people[i[1]] += 1;
    }

    for (int i = 1; i < N + 1; ++i) {
        if (people[i] == N - 1) {
            return i;
        }
    }

    return -1;
}
