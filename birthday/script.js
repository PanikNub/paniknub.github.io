"use strict";

let birthdaySong = document.getElementById("birthdaySong");
let confettiButton = document.getElementById("confettiButton");

confettiButton.onclick = function(){
    let audio = document.getElementById("confettiAudio");
    audio.play();
}