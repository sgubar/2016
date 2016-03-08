
 int doEight();
 int doEight()
 {
    int result;
    int iter = 0;
    int output[100];
    int i;
    printf("Enter the number: ");
    scanf("%d", &result);
    while(result>=8){
        output[iter] = result%8;
        result /= 8;
        iter++;
    }
    output[iter] = result;
    for(i = iter; i>=0; i--){
        printf("%d", output[i]);
    }
 }
