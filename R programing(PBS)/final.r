data = scan("file.txt",what=numeric(),sep= " ")
print (data)
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

m=sum(data)/length(data)
print("mean = ")
print(m)

z=sum(ttengah*frek)
print("z = ")
print(z)

me= z/length(data)
print("me = ")
print(me)

median=(length(data)/2)
print("med = ")
print(median)

cek <- 0
fm <- 0
bm <- 0
fkm <- 0
d1 <- 0
d2 <- 0
bol <- TRUE

for (i in 1:length(frek)) {
  cek <- cek + frek[i]
  if (cek >= median && bol == TRUE) {
    fm <- frek[i]
    bm <- kelasA[i] - 0.5
    print(bm)
    fkm <- cek - frek[i]
    bol <- FALSE
    d1 <- frek[i] - frek[i - 1]
    d2 <- frek[i] - frek[i + 1]
    break
  }
}


print("fkm = ")
print(fkm)

print("fm = ")
print(fm)

print("bm = ")
print(bm)

md<-round(bm+(interval*((((length(data)/2)-fkm)/fm))))
print("median = ")
print(md)

mo<-round(bm+(interval*(d1/(d1-d2))))
print("modus = ")
print(mo)


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

deviasi<-function(x){
  print((sum(abs(x-mean(x))))/length(x))
}
print("deviasi rata-rata tunggal : ")
deviasi(data)

deviasiK<- function(x,y,z){
  print(sum(abs(x-mean(y))*z)/length(y))
}
print("deviasi rata-rata berkelompok : ")
deviasiK(ttengah,data,frek)

print("varian Tunggal = ")
V=v(data)
print(V)
print("simpangan baku tunggal = ")
SB=(sb(data))
print(SB) 
print("varian Berkelompok = ")
varians(ttengah,data,frek)
print("simpangan baku Berkelompok = ")
smb(ttengah,data,frek)