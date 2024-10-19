"use strict";

let birthdaySong = document.getElementById("birthdaySong");
let confettiButton = document.getElementById("confettiButton");
let pikaImage = document.getElementById("pikaImage");

confettiButton.onclick = function(){
    let audio = document.getElementById("confettiAudio");
    audio.play();
}
pikaImage.onclick = function(){
    let audio = document.getElementById("pikaSound");
    audio.volume = 0.5;
    audio.play();
}