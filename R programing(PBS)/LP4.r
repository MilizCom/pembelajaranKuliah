data <- sort(sample(22:98, 70, replace = TRUE, prob = NULL))
# pdata= c(41,45,49,52,52,53,55,56,63,57,57,58,59,60,61,67,62,56,63,35,65,65,65,67,67,73,61,69,69,96,69,70,71,71,71,77,79,73,93,73,81,75,75,77,77,89,67,79,79,81,59,83,83,87,89,71,92,81,65,84,73)
# data =sort(pdata)
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

z=ttengah*frek
print("z = ")
print(z)

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

print("Data:")
print(data)
