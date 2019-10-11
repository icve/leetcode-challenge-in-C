/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int * newDigits = calloc(digitsSize, sizeof *newDigits);
    int carry = 1;
    for(int i=digitsSize - 1; i >=0; --i){
        int d = digits[i] + carry;
        if(d == 10){
            newDigits[i] = 0;
            carry = 1;
        }else{
            newDigits[i] = d;
            carry = 0;
        }
    }
    if(carry){
        // since all digits must be zero at this point
        // and the correct return should be 1 follow by digitsSize number of 0
        newDigits = realloc(newDigits, (digitsSize + 1 )* sizeof *newDigits);
        newDigits[0] = 1;
        newDigits[digitsSize] = 0;
    }
    *returnSize = digitsSize + carry;
    return newDigits;
}


