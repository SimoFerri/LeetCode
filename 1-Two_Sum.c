/*
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i, j, *result;

    *returnSize = 2;
    result = malloc(sizeof(int) * (*returnSize));
    if(result) {
        for(i = 0; i < numsSize; i++)
            for(j = i + 1; j < numsSize; j++)
                if(nums[i] + nums[j] == target) {
                    result[0] = i;
                    result[1] = j;
                    return result;
                }
    }
    return NULL;
}