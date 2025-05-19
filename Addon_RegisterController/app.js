const addon = require("./build/Release/hello");

function ControllerAddon() {
  const controller = addon.ControllerRegister("admffin", "demffo");

  return controller;
}

const express = require("express");
const app = express();
require("dotenv").config();

app.get("/register_controller", (req, res) => {
  let controllers = ControllerAddon();

  if (controllers == "Succesfuly!") {
    res.send("Controller registered successfully");
  } else {
    res.send("Controller registration failed");
  }
});

app.listen(process.env.PORT, () => {
  console.log("Server is running on port 3000");
});
