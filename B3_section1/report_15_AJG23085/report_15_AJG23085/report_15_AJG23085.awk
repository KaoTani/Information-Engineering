#AJG23085 谷口香央
#AWKはあんまり縛りがないから逆に難しかったです。

BEGIN {
    sum=0;
    sumsq=0;
    n=0;
}

{
    sum += $1;
    sumsq += $1 ^ 2;
    n++;
}

END {
    if(n>0){
        mean = sum / n;
        var = (sumsq / n) - (mean ^ 2);
        print var;
    }
}