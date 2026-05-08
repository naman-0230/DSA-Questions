// 2️⃣ Prefix Sum Approach
// 🧠 Idea

// We know:

// subarray sum = prefix[j] - prefix[i]

// To maximize:

// maximize prefix[j] - smallest prefix[i]
// 💻 Code


// int maxSubArray(vector<int>& nums) {

//     int sum = 0;
//     int minPrefix = 0;
//     int maxSum = INT_MIN;

//     for(int i = 0; i < nums.size(); i++){

//         sum += nums[i];

//         maxSum = max(maxSum, sum - minPrefix);

//         minPrefix = min(minPrefix, sum);
//     }

//     return maxSum;
// }