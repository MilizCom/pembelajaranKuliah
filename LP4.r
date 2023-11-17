data <- sort(sample(22:98, 70, replace = TRUE, prob = NULL))

k <- 1 + (3.3 * log10(length(data)))
k <- round(k)
j <- max(data) - min(data)
interval <- j / k
interval <- round(interval)

print("Interval:")
print(interval)

ak <- min(data)
frek <- 0
ttengah <- 0
while (ak <= max(data)) {
  a <- sum(data >= ak & data <= ak + interval - 1)
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

print("Frek:")
print(frek)
print("Tengah:")
print(ttengah)

# Menghitung FKM (Frekuensi Kumulatif Sebelum Kelas Tertentu)
fkm_class <- data[length(data) %/% 2 + 1]
fkm <- sum(data <= fkm_class)

print("FKM:")
print(fkm)

# Menghitung median, mean, dan nilai lainnya
med <- median(data)
mean_val <- mean(data)
posisi_median <- (length(data) + 1) / 2
median_data <- ifelse(length(data) %% 2 == 0, c(data[posisi_median], data[posisi_median + 1]), data[posisi_median])
fm <- sum(data == median_data)
n <- length(data)
batas_bawah_median <- (n + 1) / 2
if (n %% 2 == 0) {
  median_bawah <- mean(data[batas_bawah_median], data[batas_bawah_median + 1])
} else {
  median_bawah <- data[ceiling(batas_bawah_median)]
}
md <- median_bawah + (interval * ((length(data)/2 - fm) / fm))
md <- round(md)

frekuensi <- table(data)
modus <- as.numeric(names(frekuensi)[frekuensi == max(frekuensi)])
plot(ttengah,frek)
polygon(
  ttengah,frek,
  col = "lightblue",
  border = NA
)
hist(data, breaks = k, col = "lightblue", main = "Histogram", xlab = "Nilai", ylab = "Frekuensi")

print("MD:")
print(md)
print("Modus:")
print(modus)
print("Median:")
print(med)
print("Mean:")
print(mean_val)
print("Data:")
print(data)
