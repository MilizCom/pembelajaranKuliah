
v=function(x) 
{
    sum((x-mean(x))^2) / (length(x)-1)
}

varians=function(x,y,z){
    print(sum(((x-mean(y))^2)*z)/(length(y)-1))
}
sb=function(x){
    sqrt(sum(x-mean(x))^2)/(length(x)-1)
}
smb=function(x,y,z){
    print(sum(((x-mean(y))^2)/(length(y)-1)))
}

