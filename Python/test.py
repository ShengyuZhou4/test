a1,a2,a3,a4,a5=map(int,input().split())
a2+=a1//3
a5+=a1//3
a1=a1//3
a1+=a2//3
a3+=a2//3
a2=a2//3
a2+=a3//3
a4+=a3//3
a3=a3//3
a3+=a4//3
a5+=a4//3
a4=a4//3
a4+=a5//3
a1+=a5//3
a5=a5//3
print(a1,a2,a3,a4,a5)