// Given an integer array nums and an integer k, return the k most frequent elements.You may return the answer in any order.

/*
Solution Description
First, we count frequency of all the elements of the array and store them in count map. Then, we use a min heap to store the k most frequent elements. We iterate through the count map and push the elements into the heap. If the size of the heap exceeds k, we pop the top element. Finally, we return the top k elements from the heap.
We use priority queue, i.e. whenever an element with higher occurance comes, it will replace the element with lower occurance in the heap. This is because we are using min heap. Size of proirity queue is k, so it will always have k most frequent elements.

Time Complexity : O(n * log(k))
n is the number of elements in the array. We iterate through the array once and push elements into the heap. Pushing an element into the heap takes O(log(k)) time.

Space Complexity : O(n+k)
Extra space required for hashmap storage is O(n)

*/

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> count;
        for (int num : nums)
        {
            count[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for (auto &entry : count)
        {
            heap.push({entry.second, entry.first});
            if (heap.size() > k)
            {
                heap.pop();
            }
        }

        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};