# 2028. Find Missing Observations

You can find the original problem statement [here](https://leetcode.com/problems/find-missing-observations/).

## Description

The premise of the problem statement, concisely, is we originally rolled a 6-sided fair dice `n+m` times. We calculated its average and stored it in `mean`. Apparently, we have lost random `n` observations and are left with `m` observations. We need to return an array of those `n` observations.

At first this might seem completely impossible, because how can we find those exact `n` missing observations. But we are given leeway and we are told; first, we can return any array valid answers that satisfy aforementioned conditions and second, the mean is always an integer. This helps us to build towards our first step.

Given inputs,
  1. array `rolls` (size `m`)
  2. integer `mean`
  3. integer `n`

Now, lets build towards the solution.

## Walkthrough

First, we need to derive needed parameters.

```cpp
const int m = rolls.size();
int totalSum = mean*(n+m);
int sumOfMObservations = accumulate(rolls.begin(), rolls.end(), 0);
int targetSum = totalSum - sumOfMObservations;
```
* `m` := the m in `n+m`, since we already have `n` as input,
* `totalSum` := total sum of all original observations, calculated using mean times total number of observations,
* `sumOfMObservations` := sum of at present available `m` observations,
* `targetSum` := missing sum, or the sum that `n` observations add up to.

Secondly, we check if `targetSum` is even possible to achieve. The maximum sum obtained from a 6-sided dice with `n` rolls is `n*6` and minimun would be `n`. If `targetSum` is outside of this range, we can simply return an empty array.

```cpp
if (targetSum > n*6 || targetSum < n)
  return {};
```

Now, since we are assured that `targetSum` is an achievable sum, we can start calculating it. What I tried as an approach is to declare an array `ans` of size `n` and all elements being `6`.

```cpp
vector<int> ans(n,6);
```

Now, I can reduce each element such that elements of `ans` add up to `targetSum`. To achieve this, I iterated through each element,
  1. if `diff` is greater than 5, I can set current element to `1`, reduce the `diff` by `5`, and go to next element,
  2. else if `diff` is less than 6, current element is set to `diff`, and break out of the loop.

```cpp
int i = 0;
int currentSum = n*6;
int diff = currentSum-targetSum;

while (diff > 0) {
    if (diff < 6) {
        ans[i] -= diff;
        diff = 0;
    }
    else {
        ans[i] -= 5;
        diff -= 5;
        ++i;
    }
}
```

Now, simply return the `ans` array.

## [🔗Solution File](solution.cpp)