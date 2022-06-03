#include<Arduino.h>

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
  <head>
    <title>MK_CAR</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
      body { font-family: Arial; text-align: center; margin:0px auto; padding-top: 30px; position: relative}
      .btns1{
        position: absolute;
        left: 45%;
        top: 150px;
      }
      .btns2{
        position: absolute;
        left: 10%;
        top: 300px;
      }
      .btns3{
        position: absolute;
        left: 80%;
        top: 300px;
      }
      .btns4{
        position: absolute;
        left: 45%;
        top: 450px;
      }
      .btns5{
        position: absolute;
        left: 45%;
        top: 600px;
      }
      .btns6{
        position: absolute;
        left: 45%;
        top: 300px;
      }
      .button {
        padding: 20px 20px;
        font-size: 24px;
        text-align: center;
        outline: none;
        color: #fff;
        background-color: #2f4468;
        border: none;
        border-radius: 20px;
        box-shadow: 0 6px #999;
        cursor: pointer;
        -webkit-touch-callout: none;
        -webkit-user-select: none;
        -khtml-user-select: none;
        -moz-user-select: none;
        -ms-user-select: none;
        user-select: none;
        -webkit-tap-highlight-color: rgba(0,0,0,0);
      }  
      .button:hover {background-color: #1f2e45}
      .button:active {
        background-color: #1f2e45;
        box-shadow: 0 4px #666;
        transform: translateY(2px);
      }
      .button2 {
        padding: 20px 20px;
        font-size: 24px;
        text-align: center;
        outline: none;
        color: #fff;
        background-color: #2f4468;
        border: none;
        border-radius: 50%;
        box-shadow: 0 6px #999;
        cursor: pointer;
        -webkit-touch-callout: none;
        -webkit-user-select: none;
        -khtml-user-select: none;
        -moz-user-select: none;
        -ms-user-select: none;
        user-select: none;
        -webkit-tap-highlight-color: rgba(0,0,0,0);
      }  
      .button2:hover {background-color: #1f2e45}
      .button2:active {
        background-color: #1f2e45;
        box-shadow: 0 4px #666;
        transform: translateY(2px);
      }
      
    </style>
  </head>
  <body>
    <h1>MK_CAR</h1>
    <div class='btns1'>
          <button class="button" onmousedown="toggleCheckbox('on1');" ontouchstart="toggleCheckbox('on1');" onmouseup="toggleCheckbox('off1');" ontouchend="toggleCheckbox('off1');">D</button>
    </div>
    <div class='btns2'>
          <button class="button" onmousedown="toggleCheckbox('on2');" ontouchstart="toggleCheckbox('on2');" onmouseup="toggleCheckbox('off2');" ontouchend="toggleCheckbox('off2');">L</button>
    </div>
    <div class='btns3'>
          <button class="button" onmousedown="toggleCheckbox('on3');" ontouchstart="toggleCheckbox('on3');" onmouseup="toggleCheckbox('off3');" ontouchend="toggleCheckbox('off3');">R</button>
    </div>
    <div class='btns4'>
          <button class="button" onmousedown="toggleCheckbox('on4');" ontouchstart="toggleCheckbox('on4');" onmouseup="toggleCheckbox('off4');" ontouchend="toggleCheckbox('off4');">B</button>
    </div>
    <div class='btns5'>
          <button class="button2" onmousedown="toggleCheckbox('on5');" ontouchstart="toggleCheckbox('on5');" onmouseup="toggleCheckbox('off5');" ontouchend="toggleCheckbox('off5');">E</button>
    </div>
    <div class='btns6'>
          <button class="button" onmousedown="toggleCheckbox('on6');" ontouchstart="toggleCheckbox('on6');" onmouseup="toggleCheckbox('off6');" ontouchend="toggleCheckbox('off6');">C</button>
    </div>
   <script>
   function toggleCheckbox(x) {
     var xhr = new XMLHttpRequest();
     xhr.open("GET", "/" + x, true);
     xhr.send();
   }
  </script>
  </body>
</html>)rawliteral";