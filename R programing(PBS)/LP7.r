# data =c(41,45,49,51,52,53,55,56,63,57,57,58,59,60,61,67,62,56,63,35, 65,65,65,67,67,73,61,69,69,96,69,70,71,71,77,79,73,93,73,81,75,75,77,77,89,67,79,79,81,59,83,83,87,89,71,92,81,65,84,73)
data <- c(35, 45, 28, 130, 75, 40, 50, 120, 28, 60, 80, 90, 110, 30, 70, 100, 140, 29, 95, 130,60, 45, 28, 70, 120, 80, 50, 35, 28, 110, 140, 90, 75, 30, 100, 130, 28, 95, 40, 60, 110,120, 70, 45, 80, 140, 50, 29, 28, 30, 75, 130, 60, 28, 100, 90, 110, 120, 35, 140, 45, 80,70, 50, 95, 29, 60, 110, 140, 100, 28, 75, 30, 120, 35, 80, 70, 45, 50, 29, 95, 110, 140,60, 28, 100, 75, 120, 30, 80, 35, 29, 50, 70, 95, 140, 60, 28, 110, 100, 75, 45, 80, 120)
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
