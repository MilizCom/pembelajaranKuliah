pdata= c(3,8,3,5,9,19,7,3,7,21,76,67,32,45,76,24,89,9,65,22,44,77,32,3,4)
data =sort(pdata)
k <- 1 + (3.3 * log10(length(data)))
k <- round(k)
j <- max(data) - min(data)
interval <- j / k
interval <- round(interval)

print("Interval:")
print(interval)

ak <- min(data)
kelas<-0
frek <- 0
ttengah <- 0
while (ak <= max(data)) {
  a <- sum(data >= ak & data <= ak + interval - 1)
  print(ak)
  Kelas = c(kelas,ak)
  if (frek:1 != 0) {
    frek <- c(frek, a)
  } else {
    frek <- a
  }
  if (ttengah:1 != 0) {
    ttengah <- c(ttengah, median(data[data >= ak & data <= ak + interval - 1]))
  } else {
    ttengah <- median(data[data >= ak & data <= ak + interval - 1])
  }
  ak <- ak + interval
}
print(frek)
print(kelas)
n=length(data)

q1=round(n/4)
q2=round(n/2)
q3=round(3*n/4)
bq1=3
bq3=30.5
fkq1=11
fkq3=18
fq1=11
fq3=3
Q1=bq1+(interval*(((length(data)/4)-fkq1))/fq1)
q3=bq3+(interval*(((3*length(data)/4)-fkq3))/fq3)
ld1=length(data)/10
ld2=2*length(data)/20
ld3=3*length(data)/30
ld4=4*length(data)/40
ld5=5*length(data)/50
ld6=6*length(data)/60
ld7=6*length(data)/70
ld8=8*length(data)/80
ld9=9*length(data)/90

print(q1)
print(q2) 
print(q3)
print(n)
print(data)