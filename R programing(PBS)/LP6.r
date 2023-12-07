data = c(8, 59, 37, 123, 19, 98, 161, 275, 46, 217, 92, 319, 180, 379, 143, 43, 258, 107, 376, 214,67, 309, 133, 232, 75, 197, 358, 101, 35, 154,278, 148, 287, 66, 335, 52, 223, 114, 337, 189,42, 260, 85, 339, 160, 64, 301, 222, 108, 329,199,89, 264, 117, 189, 320, 140, 236, 54, 303,126, 357, 232, 99, 26, 175, 329, 76, 212, 339,184, 92, 295, 140, 36, 261, 113, 352, 204, 15,233, 34, 155, 279, 120, 352, 184, 376, 144, 81,219, 41, 307, 176, 338, 92, 19, 271, 126, 293,147, 64, 327, 180, 366, 120, 49, 268, 99, 359,215, 56, 289, 129, 238, 70, 191, 352, 98, 318,171, 52, 313, 171, 374, 104, 29, 233, 88, 340,192, 90, 299, 156, 75, 278, 119, 357, 210, 31,248, 11, 182, 317, 84, 355, 212, 321, 164, 50,282, 145, 350, 68, 217, 98, 24, 246, 109, 365,128, 235, 66, 296, 163, 352, 88, 7, 214, 93,325, 176, 342, 132, 241, 60, 201, 358, 101, 311,160, 55, 282, 132, 31, 254, 105, 348, 201, 86)
data = round(data)
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

n <- length(data)
persentil <- numeric(0)

# Calculate percentiles for each iteration
for (i in 1:100) {
    p <- ((i  * (n + 1)) / 100)
    persentil <- c(persentil, p)
}

print("Persentil:")
print(persentil)

pk <- numeric(0)

for (i in 1:100) {
    f <- 0
    bkp <- 0
    fkp <- 0
    cek <- 0
    for (j in 1:length(frek)) {
        cek <- cek + frek[j]
        if (cek >= persentil[i]) {
            f <- frek[j]
            bkp <- kelasA[j] - 0.5
            fkp <- cek - frek[j]
            break
        }
    }
    K <- bkp + ((((i * n) / 100) - fkp) / f) * n
    pk <- c(pk, K)
}
print("Persentil ke-r:")
print(pk)
mean=mean(data)
md <-sum(abs(data - mean)) / n
print ("deviasi rata 2 tunggal: ")
print(md)

fi = sum(frek)
xi=sum(ttengah)
meanV=xi/fi
print("fi :")
print(fi)
print("xi :")
print(xi)
print("meanV =")
print(meanV)

mdk<-sum(fi * (xi - meanV)) / length(data)

print ("deviasi rata 2 kelompok:  ")
print(mdk)

