// Smooth scroll
document.querySelectorAll('a[href^="#"]').forEach(anchor => {
    anchor.addEventListener('click', function (e) {
        e.preventDefault();

        document.querySelector(this.getAttribute('href')).scrollIntoView({
            behavior: 'smooth'
        });
    });
});

// Toggle warna latar navbar saat di-scroll
window.addEventListener('scroll', function() {
    var navbar = document.querySelector('.navbar');
    navbar.classList.toggle('navbar-scroll', window.scrollY > 0);
});

// Timer hitung mundur
var weddingDate = new Date('2024-04-24T08:00:00');
var countdownElement = document.getElementById('countdown');

function updateCountdown() {
    var currentDate = new Date();
    var timeDifference = weddingDate - currentDate;

    var days = Math.floor(timeDifference / (1000 * 60 * 60 * 24));
    var hours = Math.floor((timeDifference % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
    var minutes = Math.floor((timeDifference % (1000 * 60 * 60)) / (1000 * 60));
    var seconds = Math.floor((timeDifference % (1000 * 60)) / 1000);

    countdownElement.innerHTML = days + ' hari ' + hours + ' jam ' + minutes + ' menit ' + seconds + ' detik';
}

// Perbarui setiap detik
setInterval(updateCountdown, 1000);

// Toggle tampilan peta
var mapSection = document.getElementById('map');
var mapButton = document.querySelector('.map_list');

mapButton.addEventListener('click', function() {
    mapSection.classList.toggle('map-hidden');
});
 
// Galeri dengan Lightbox
var galleryImages = document.querySelectorAll('.gallery_list img');

galleryImages.forEach(image => {
    image.addEventListener('click', function() {
        var overlay = document.createElement('div');
        overlay.className = 'overlay';

        var largeImage = document.createElement('img');
        largeImage.src = this.src;
        largeImage.className = 'large-image';

        overlay.appendChild(largeImage);
        document.body.appendChild(overlay);

        overlay.addEventListener('click', function() {
            overlay.remove();
        });
    });
});
// Animasi tombol submit
var submitButton = document.querySelector('#buku_tamu form button');

submitButton.addEventListener('mouseenter', function() {
    this.classList.add('button-hover');
});

submitButton.addEventListener('mouseleave', function() {
    this.classList.remove('button-hover');
});
let map;

async function initMap() {
  const { Map } = await google.maps.importLibrary("maps");

  map = new Map(document.getElementById("map"), {
    center: { lat: -34.397, lng: 150.644 },
    zoom: 8,
  });
}

initMap();

var backgroundMusic = document.getElementById('backgroundMusic');

  // Mulai otomatis pemutaran audio saat halaman dimuat
  window.onload = function () {
    backgroundMusic.play();
  };

  // Sembunyikan pemutar audio
  backgroundMusic.style.display = 'none';