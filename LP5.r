# pdata= c(41,45,49,52,52,53,55,56,63,57,57,58,59,60,61,67,62,56,63,35,65,65,65,67,67,73,61,69,69,96,69,70,71,71,71,77,79,73,93,73,81,75,75,77,77,89,67,79,79,81,59,83,83,87,89,71,92,81,65,84,73)
# data =sort(pdata)
# n=length(data)
# q1=n/4
# q2=n/2
# q3=3*n/4
# bq1=52.5
# bq3=70.5
# fkq1=6
# fkq3=33
# fq1=12
# fq3=15


# print(q1)
# print(q2) 
# print(q3)
# print(n)
# print(data)



data <-sort( sample(16:100, 100, replace = TRUE))

k <- 1 + (3.3 * log10(length(data)))
k <- round(k)
j <- max(data) - min(data)
interval <- j / k
interval <- round(interval)
print("Interval:")
print(interval)
b <- 0
ak <- min(data)
kelasA <- numeric(0)
kelasB <- numeric(0)
frek <- numeric(0)
ttengah <- numeric(0)
while (ak <= max(data)) {
  a <- sum(data >= ak & data <= ak + interval - 1)

  print(ak)
  if (length(frek) != 0) {
    frek <- c(frek, a)
    kelasA <- c(kelasA, ak)
    kelasB <- c(kelasB, ak + interval - 1)
  } else {
    frek <- a
    kelasA <- ak
    kelasB <- ak + interval - 1
  }
  if (length(ttengah) != 0) {
    ttengah <- c(ttengah, median(data[data >= ak & data <= ak + interval - 1]))
  } else {
    ttengah <- median(data[data >= ak & data <= ak + interval - 1])
  }
  ak <- ak + interval
}

print("Frek:")
print(frek)
print("Tengah:")
print(ttengah)

tabel_frekuensi <- data.frame(
  Kelas = paste(kelasA, kelasB, sep = "-"),
  Frekuensi = frek,
  Median = ttengah
)
print("Tabel Frekuensi:")
print(tabel_frekuensi)

lq1<-length(data)/4
lq2<-length(data)/2
lq3<-(3*length(data))/4


print("lq1 : ")
print(lq1)
print("lq2 : ")
print(lq2)
print("lq3 : ")
print(lq3)

cek <- 0
bq1 <- 0
bq3 <- 0
fkq1 <- 0
fkq3 <- 0
fq1 <- 0
fq3 <- 0
bol <- TRUE

for (i in 1:length(frek)) {
  cek <- cek + frek[i]
  if (cek > lq1 && bol == TRUE) {
    fq1 <- frek[i]
    bq1 <- kelasA[i] - 0.5
    fkq1 <- cek - frek[i]
    bol <- FALSE
    break
  }
}

print("fq1 : ")
print(fq1)
print("bq1 : ")
print(bq1)
print("fkq1 : ")
print(fkq1)
bol <- TRUE

for (i in 1:length(frek)) {
  cek <- cek + frek[i]
  if (cek > lq3 && bol == TRUE) {
    fq3 <- frek[i]
    bq3 <- kelasA[i] - 0.5
    fkq3 <- cek - frek[i]
    bol <- FALSE
    break
  }
}


print("fq3 : ")
print(fq3)
print("bq3 : ")
print(bq3)
print("fkq3 : ")
print(fkq3)

q1<-bq1+(interval*(((length(data)/4)-fkq1))/fq1)
q3<-bq3+(interval*(((3*length(data)/4)-fkq3))/fq3)

print("quartil 1 : ")
print(q1)

print("quartil 3 : ")
print(q3)
d<-0
for (i in 1:10) {
  d[i]<-(i*length(data))/10
  cat("decil ke : ",i)
  print(d[i])
}

print(data)