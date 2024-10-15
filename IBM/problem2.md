# Problem: Gas Station

## Problem Description

There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.


Example 1:

Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3


Example 2:

Input: gas = [2,3,4], cost = [3,4,3]
Output: -1


Constraints:

n == gas.length == cost.length
1 <= n <= 105
0 <= gas[i], cost[i] <= 104

SOLUTION

Language- C++

class Solution {
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int total_gas = 0, total_cost = 0, tank = 0, start_index = 0;
    
        for (int i = 0; i < gas.size(); i++)
        {
            total_gas += gas[i];
            total_cost += cost[i];
            tank += gas[i] - cost[i];
    
            if (tank < 0)
            {
                start_index = i + 1;
                tank = 0;
            }
        }
    
        return (total_gas >= total_cost) ? start_index : -1;
    }
};

