// Problem: Number of Nice Subarrays
// 📌 Problem Statement

// Given an array nums and an integer k:

// 👉 Count the number of subarrays with exactly k odd numbers

// 🧪 Example
// nums = [1,1,2,1,1], k = 3

// Valid subarrays:

// [1,1,2,1]
// [1,2,1,1]

// 👉 Answer = 2

// 🔥 Key Observation

// Convert problem into:

// count subarrays with sum = k

// How?

// 👉 Treat:

// odd → 1
// even → 0