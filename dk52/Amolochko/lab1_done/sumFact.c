int sumFact(int num, int numm){
    int sum = 0;
    for(int D=0;D <= num;D++)
	{
		numm+=D;
        sum+=fact(numm);
    }
    return sum;
}
