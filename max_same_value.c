int maxConsecutiveAnswers(char * answerKey, int k){
    int count = sizeof(answerKey);
    int index = 0;
    int start = 0;
    int end = 0;
    while (start < count)
    {
        int k1 = k;
        start = end = index;
        while (k1 > 0 || (answerKey[end] == answerKey[start]))
        {
            if (answerKey[start] != answerKey[end])
            {
                if (k1 == k)
                {
                   index = end;   
                }
                k1--;
            }
            end++;
        }
    }
    return end - start;
}