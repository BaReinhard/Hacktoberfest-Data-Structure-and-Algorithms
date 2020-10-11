println("Enter number of elements in array : ")
inp=readline()
n=parse(Int64,inp)
println("Enter $n elements : ")
inp=readline()
a=[parse(Int64,inp)]
for i in 2:n
inp=readline()
push!(a,parse(Int64,inp))
end
for i in 1:n
for j in 1:n-1
if(a[j]>a[j+1])
temp=a[j]
a[j]=a[j+1]
a[j+1]=temp
end
end
end
print(a)