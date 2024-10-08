"use strict";

let displayHealth = document.getElementById("displayHealth"); let displayRespect = document.getElementById("displayRespect");
let displayLose = document.getElementById("displayLose");

let fightCurse = document.getElementById("fightCurse");
let rest = document.getElementById("rest");

let health = 100;
let respect = 0;

let displayStatus = () => {displayHealth.textContent = `Health: ${health}`; displayRespect.textContent = `Respect: ${respect}`;};

fightCurse.onclick = function(){
    if(health > 0){
        let damage = Math.floor(Math.random() * 100);
        let earn = Math.floor(Math.random() * 10);

        health -= damage;
        respect += earn;
        displayStatus();
    }
}
rest.onclick = function(){
    if(health > 0){
        let heal = Math.floor(Math.random() * 50);

        health += heal;
        respect--;

        displayStatus();
    }
}