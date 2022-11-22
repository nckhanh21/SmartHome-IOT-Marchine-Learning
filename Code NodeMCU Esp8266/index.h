const char MainPage[] PROGMEM = R"=====(
  <!DOCTYPE html>
<html>

<head>
  <script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.9.4/Chart.js">
  </script>
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
  <script src="https://kit.fontawesome.com/c4dd8597cc.js" crossorigin="anonymous"></script>
  <title>N19-Smart Home</title>
  <style>
    body {
      text-align: center;
      background: linear-gradient(to right, #360033, #0b8793);
      color: white
    }


    .loading {
      position: relative;
      width: 2em;
      height: 2em;
      border: 3px solid #3cefff;
      overflow: hidden;
      animation: spin 3s ease infinite;
    }

    .loading::before {
      content: '';
      position: absolute;
      top: -3px;
      left: -3px;
      width: 2em;
      height: 2em;
      background-color: hsla(185, 100%, 62%, 0.75);
      transform-origin: center bottom;
      transform: scaleY(1);
      animation: fill 3s linear infinite;
    }

    @keyframes spin {

      50%,
      100% {
        transform: rotate(360deg);
      }
    }

    @keyframes fill {

      25%,
      50% {
        transform: scaleY(0);
      }

      100% {
        transform: scaleY(1);
      }
    }

    button {
      z-index: 1;
      position: relative;
      font-size: inherit;
      font-family: inherit;
      color: white;
      padding: 0.5em 1em;
      outline: none;
      border: none;
      background-color: hsl(236, 32%, 26%);
      overflow: hidden;
      transition: color 0.4s ease-in-out;
    }

    button::before {
      content: '';
      z-index: -1;
      position: absolute;
      top: 100%;
      right: 100%;
      width: 1em;
      height: 1em;
      border-radius: 50%;
      background-color: #3cefff;
      transform-origin: center;
      transform: translate3d(50%, -50%, 0) scale3d(0, 0, 0);
      transition: transform 0.45s ease-in-out;
    }

    button:hover {
      cursor: pointer;
      color: #161616;
    }

    button:hover::before {
      transform: translate3d(50%, -50%, 0) scale3d(15, 15, 15);
    }

    input {
      height: 25px;
      width: 270px;
      font-size: 20px;
      margin: 10px auto;
    }

    #content {
      border: white solid 1px;
      padding: 5px;
      height: 680px;
      width: 330px;
      border-radius: 20px;
      margin: 0 auto
    }

    .ledstatus {
      outline: none;
      margin: 15px 5px;
      width: 60px;
      height: 60px;
      border-radius: 50%;
      -moz-border-radius: 50%;
      -webkit-border-radius: 50%;
      color: white;
      font-size: 20px;
      font-weight: bold;
    }

    #ledstatus1 {
      border: solid 2px #23C48E;
      background: #23C48E;
    }

    #ledstatus2 {
      border: solid 2px #ED9D00;
      background: #ED9D00;
    }

    #ledstatus3 {
      border: solid 2px #5F7CD8;
      background: #5F7CD8;
    }

    #ledstatus4 {
      border: solid 2px #03C0F8;
      background: #03C0F8;
    }

    #ledconnect {

      outline: none;
      margin: 0px 5px -1px 5px;
      width: 15px;
      height: 15px;
      border: solid 1px #00EE00;
      background-color: #00EE00;
      border-radius: 50%;
      -moz-border-radius: 50%;
      -webkit-border-radius: 50%;
    }

    .button {
      height: 65px;
      width: 70px;
      margin: 10px 0;
      background-color: #3C89BC;
      border-radius: 10px;
      outline: none;
      color: white;
      font-size: 25px;
      font-weight: bold;
    }

    .button_all {
      height: 70px;
      width: 140px;
      margin: 10px 0;
      outline: none;
      color: white;
      font-size: 20px;
      font-weight: bold;
    }

    #button_on {
      background: linear-gradient(to right, #11998e, #38ef7d);
      border-radius: 10px;
    }

    #button_off {
      background: linear-gradient(to right, #333333, #dd1818);
      border-radius: 10px;
    }

    .button_setup {
      height: 30px;
      width: 280px;
      margin: 10px 0;
      background-color: #3C89BC;
      border-radius: 10px;
      outline: none;
      color: white;
      font-size: 20px;
      font-weight: bold;
    }

    .button_wifi {
      height: 50px;
      width: 90px;
      margin: 10px 0;
      outline: none;
      color: white;
      font-size: 15px;
      font-weight: bold;
    }

    #button_save {
      background-color: #00BB00;
      border-radius: 5px;
    }

    #button_restart {
      background-color: #FF9900;
      border-radius: 5px;
    }

    #button_reset {
      background-color: #CC3300;
      border-radius: 5px;
    }

    .dht11 {
      /* width: 50%; */
      margin-bottom: 10px;
      padding: 10px;
    }

    #footer {
      margin-top: 50px;
    }

    .toggle-container {
      max-width: 1000px;
      width: 100%;
      display: flex;
      flex-wrap: wrap;
      justify-content: space-around;
    }

    .switch-holder {
      background-color: #d1dad3;
      display: flex;
      padding: 10px 20px;
      border-radius: 10px;
      margin-bottom: 30px;
      box-shadow: -8px -8px 15px rgba(27, 25, 25, 0.7),
        10px 10px 10px rgba(0, 0, 0, .3),
        inset 8px 8px 15px rgba(255, 255, 255, .7),
        inset 10px 10px 10px rgba(0, 0, 0, .3);
      justify-content: space-between;
      align-items: center;
    }

    .switch-label {
      width: 150px;
    }

    .switch-label i {
      margin-right: 5px;
    }

    .switch-toggle {
      height: 40px;
    }

    .switch-toggle input[type="checkbox"] {
      position: absolute;
      opacity: 0;
      z-index: -2;
    }

    .switch-toggle input[type="checkbox"]+label {
      position: relative;
      display: inline-block;
      width: 100px;
      height: 40px;
      border-radius: 20px;
      margin: 0;
      cursor: pointer;
      box-shadow: inset -8px -8px 15px rgba(255, 255, 255, .6),
        inset 10px 10px 10px rgba(0, 0, 0, .25);

    }

    .switch-toggle input[type="checkbox"]+label::before {
      position: absolute;
      content: 'OFF';
      font-size: 13px;
      text-align: center;
      line-height: 25px;
      top: 8px;
      left: 8px;
      width: 45px;
      height: 25px;
      border-radius: 20px;
      box-shadow: -3px -3px 5px rgba(255, 255, 255, .5),
        3px 3px 5px rgba(0, 0, 0, .25);
      transition: .3s ease-in-out;
    }

    .switch-toggle input[type="checkbox"]:checked+label::before {
      left: 50%;
      content: 'ON';
      color: #fff;
      background-color: #00b33c;
      box-shadow: -3px -3px 5px rgba(255, 255, 255, .5),
        3px 3px 5px #00b33c;
    }

    .toggle-body {
      font-family: 'Poppins', sans-serif;
      margin-top: 20px;
      /* background-color: #d1dad3; */
      display: flex;
      justify-content: center;
      align-items: center;
      font-size: 17px;
      border-radius: 30px;
      color: #161616;
    }

    .clock {
      /* position: absolute; */
      /* top: 50%;
      left: 50%; */
      /* transform: translateX(-50%) translateY(-50%); */
      color: #17D4FE;
      font-size: 20px;
      font-family: "Orbitron";
      letter-spacing: 2px;
      margin-bottom: 20px;
    }


    /* svg {
      display: block;
      position: absolute;
      top: 50%;
      left: 50%;
      transform: translate(-50%, -50%);
    } */

    /* .filler {
      background: #20B7AF;
      position: absolute;
      bottom: 50%;
      top: 0;
      left: 0;
      right: 0;
    } */
  </style>
  <meta name="viewport" content="width=device-width,user-scalable=0" charset="UTF-8">
</head>

<body>
  <div>
    <h1>Smart Home</h1>
  </div>
  <div class="filler"></div>
  <svg width="200" height="200">

    <filter id="innerShadow" x="-20%" y="-20%" width="140%" height="140%">
      <feGaussianBlur in="SourceGraphic" stdDeviation="3" result="blur" />
      <feOffset in="blur" dx="2.5" dy="2.5" />
    </filter>

    <g>
      <circle id="shadow" style="fill:rgba(0,0,0,0.1)" cx="97" cy="100" r="87" filter="url(#innerShadow)"></circle>
      <circle id="circle" style="stroke: #FFF; stroke-width: 12px; fill:#20B7AF" cx="100" cy="100" r="80"></circle>
    </g>
    <g>
      <line x1="100" y1="100" x2="100" y2="55" transform="rotate(80 100 100)"
        style="stroke-width: 3px; stroke: #fffbf9;" id="hourhand">
        <animatetransform attributeName="transform" attributeType="XML" type="rotate" dur="43200s"
          repeatCount="indefinite" />
      </line>
      <line x1="100" y1="100" x2="100" y2="40" style="stroke-width: 4px; stroke: #fdfdfd;" id="minutehand">
        <animatetransform attributeName="transform" attributeType="XML" type="rotate" dur="3600s"
          repeatCount="indefinite" />
      </line>
      <line x1="100" y1="100" x2="100" y2="30" style="stroke-width: 2px; stroke: #C1EFED;" id="secondhand">
        <animatetransform attributeName="transform" attributeType="XML" type="rotate" dur="60s"
          repeatCount="indefinite" />
      </line>
    </g>
    <circle id="center" style="fill:#128A86; stroke: #C1EFED; stroke-width: 2px;" cx="100" cy="100" r="3"></circle>
  </svg>



  <div id="MyClockDisplay" class="clock" onload="showTime()"></div>


  <div style="width:100%; display:flex ; justify-content:center; ">
    <div
      style="padding: 10px;  background:linear-gradient(to right, #2980b9, #6dd5fa, #ffffff);  border: 1px solid rgb(0, 0, 0); width: 200px; color: rgb(29, 36, 70); border-radius: 15px; margin-right: 100px; font-weight: bold; ">
      <span id="advice">...</span>
    </div>
  </div>
  <div style="width:100%; display:flex ; justify-content:center; margin: 0px 0px;">
    <div style="
      width: 300px;
      height: 200px;
      background-image: url('https://scontent.fhan2-5.fna.fbcdn.net/v/t1.15752-9/311127770_661103472148317_4086458328853301838_n.png?_nc_cat=109&ccb=1-7&_nc_sid=ae9488&_nc_ohc=FzyRxNGnGlMAX92IUUd&_nc_ht=scontent.fhan2-5.fna&oh=03_AdRVpuy_g9rVo0CGi-bubJzLBh5DB9hjmLwrkddYvev5iA&oe=639C69FD');
      background-repeat: no-repeat;
      background-size: contain;">
    </div>
  </div>


  <div class="dht11">
    Nhiệt độ : <span id="nhietdos">0</span>°C<br>
    Độ Ẩm : <span id="doams">0</span>%<br>
    Ánh nắng : <span id="anhsangs">Sáng</span><br>
  </div>

  <div style="width:100%; display:flex ; justify-content:center; margin: 20px 0px;">
    <canvas id="myChart" style="width:100%;max-width:600px"></canvas>
  </div>

  </div>

  <div style="width:100%; display:flex ; justify-content:center; margin: 20px 0px;">
    <canvas id="myChart2" style="width:100%;max-width:600px"></canvas>
  </div>



  <!-- toggle -->
  <!-- <div class="toggle-body">
    <div class="toggle-container">
      <div class="switch-holder">
        <div class="switch-label">
          <i class="fa fa-bluetooth-b"></i><span>Bluetooth</span>
        </div>
        <div class="switch-toggle">
          <input checked="true" type="checkbox" id="bluetooth">
          <label for="bluetooth"></label>
        </div>
      </div>

    </div>
  </div> -->
  <!-- a button switch the value of bluetooth toggle -->
  <!-- <div style="width:100%; display:flex ; justify-content:center; margin: 20px 0px;">
    <button id="btn" onclick="switchValueBluetooth()">ON</button>
  </div> -->




  <div id="content">
    <div style="margin:10px 0px 10px 145px;">
      <div class="loading"></div>
    </div>

    <div id="homecontrol" style="height:340px" ;>
      <div>
        <input id="ledstatus1" hidden class="ledstatus" type="button" value="ON" />
        <input id="ledstatus2" class="ledstatus" type="button" value="ON" />
        <input id="ledstatus3" class="ledstatus" type="button" value="ON" />
        <input id="ledstatus4" class="ledstatus" type="button" value="ON" />
      </div>
      <div>
        <button class="button" style=" height: 5px; padding: 0px; background-color: red;" onclick=getbutton(1)></button>
        <button class="button" style=" height: 5px; padding: 0px; " onclick=getbutton(2)></button>
        <button class="button" style=" height: 5px; padding: 0px; background-color: yellow;" onclick=getbutton(3)></button>
        <button class="button" style=" height: 5px; padding: 0px; background-color: #00b33c;" onclick=getbutton(4)></button>
      </div>

      <!-- toggle -->
      <div>
        <div class="toggle-body">
          <div class="toggle-container">
            <div class="switch-holder">
              <div class="switch-label">
                <i class="fa fa-tv"></i><span>Thiết bị 1</span>
              </div>
              <div class="switch-toggle">
                <input type="checkbox" id="thietbi1">
                <label onclick=getbutton(2) for="thietbi1"></label>
              </div>
            </div>
            <div class="switch-holder">
              <div class="switch-label">
                <i class="fa fa-lightbulb"></i><span>Thiết bị 2</span>
              </div>
              <div class="switch-toggle">
                <input type="checkbox" id="thietbi2">
                <label onclick=getbutton(3) for="thietbi2"></label>
              </div>
            </div>
            <div class="switch-holder">
              <div class="switch-label">
                <i class="fa fa-droplet"></i><span>Thiết bị 3</span>
              </div>
              <div class="switch-toggle">
                <input type="checkbox" id="thietbi3">
                <label onclick=getbutton(4) for="thietbi3"></label>
              </div>
            </div>
          </div>
        </div>
      </div>
      <!-- het toggle-->



      <div>
        <button id="button_on" class="button_all" onclick="getbuttonall('on')">Bật tất cả</button>
        <button id="button_off" class="button_all" onclick="getbuttonall('off')">Tắt tất cả</button>
      </div>
      <div><input class="button_setup" type="button" onclick="configurewifi()" value="Thiết lập wifi" /></div>
      <div>IP connected: <b>
          <pan id="ipconnected"></pan>
        </b></div>
    </div>

    <div id="wifisetup" style="height:340px; font-size:20px; display:none" ;>
      <div style="text-align:left; width:270px; margin:5px 25px">SSID: </div>
      <div><input id="ssid" /></div>
      <div style="text-align:left; width:270px; margin:5px 25px">Password: </div>
      <div><input id="pass" /></div>
      <div>
        <button id="button_save" class="button_wifi" onclick="writeEEPROM()">SAVE</button>
        <button id="button_restart" class="button_wifi" onclick="restartESP()">RESTART</button>
        <button id="button_reset" class="button_wifi" onclick="clearEEPROM()">RESET</button>
      </div>
      <div><input class="button_setup" type="button" onclick="backHOME()" value="Back home" /></div>
      <div id="reponsetext"></div>
    </div>
  </div>
  <div><input id="ledconnect" type="button" />Connection status</div>

  <div id="footer">
    <p><i>Thành viên: <br> <b> Nguyễn Công Khánh</b>
        <br> <b> Ngô Thế Nghĩa</b> <br> <b>Chu Minh Hoàng</b>
    </p>
  </div>
  <script>

    var hands = [];
    hands.push(document.querySelector('#secondhand > *'));
    hands.push(document.querySelector('#minutehand > *'));
    hands.push(document.querySelector('#hourhand > *'));

    var cx = 100;
    var cy = 100;

    function shifter(val) {
      return [val, cx, cy].join(' ');
    }

    var date = new Date();
    var hoursAngle = 360 * date.getHours() / 12 + date.getMinutes() / 2;
    var minuteAngle = 360 * date.getMinutes() / 60;
    var secAngle = 360 * date.getSeconds() / 60;

    hands[0].setAttribute('from', shifter(secAngle));
    hands[0].setAttribute('to', shifter(secAngle + 360));
    hands[1].setAttribute('from', shifter(minuteAngle));
    hands[1].setAttribute('to', shifter(minuteAngle + 360));
    hands[2].setAttribute('from', shifter(hoursAngle));
    hands[2].setAttribute('to', shifter(hoursAngle + 360));

    for (var i = 1; i <= 12; i++) {
      var el = document.createElementNS('http://www.w3.org/2000/svg', 'line');
      el.setAttribute('x1', '100');
      el.setAttribute('y1', '30');
      el.setAttribute('x2', '100');
      el.setAttribute('y2', '40');
      el.setAttribute('transform', 'rotate(' + (i * 360 / 12) + ' 100 100)');
      el.setAttribute('style', 'stroke: #ffffff;');
      document.querySelector('svg').appendChild(el);
    }
    //Đồng hồ thời gian
    function showTime() {
      var date = new Date();
      var h = date.getHours(); // 0 - 23
      var m = date.getMinutes(); // 0 - 59
      var s = date.getSeconds(); // 0 - 59
      var session = "AM";

      if (h == 0) {
        h = 12;
      }

      if (h > 12) {
        h = h - 12;
        session = "PM";
      }

      h = (h < 10) ? "0" + h : h;
      m = (m < 10) ? "0" + m : m;
      s = (s < 10) ? "0" + s : s;

      var time = h + ":" + m + ":" + s + " " + session;
      document.getElementById("MyClockDisplay").innerText = time;
      document.getElementById("MyClockDisplay").textContent = time;

      setTimeout(showTime, 1000);

    }

    showTime();



    // Vẽ biểu đồ nhiệt độ độ ẩm 

    var data = [];
    var xValues = [0, 0, 0, 0, 0, 0, 0];
    var yValues = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
    var x1Values = [0, 0, 0, 0, 0, 0, 0];
    var y1Values = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0];



    function getDataAPI() {
      var requestOptions = {
        method: 'GET',
      };
      fetch("https://sensor.herokuapp.com/get_15", requestOptions)
        .then(response => response.text())
        .then(result => {
          var xLabel = []
          var yLabel = []
          var x1Label = []
          var y1Label = []
          data = JSON.parse(result);
          console.log(data);
          data.map((item, index) => {
            console.log(`item`, item.temperature);
            xLabel.push(item.time)
            yLabel.push(item.temperature)
            x1Label.push(item.time)
            y1Label.push(item.humidity)
          });

          // x1Values = xLabel
          // yValues = yLabel
          console.log("xLabel", xLabel);

          xValues = xLabel
          yValues = yLabel
          x1Values = x1Label
          y1Values = y1Label
          new Chart("myChart", {
            type: "line",
            data: {
              labels: xValues,
              datasets: [{
                fill: false,
                lineTension: 0,
                backgroundColor: "rgba(0,0,255,1.0)",
                borderColor: "#ED9D00",
                data: yValues
              }]
            },
            options: {
              legend: { display: false },
              title: {
                display: true,
                text: 'Biểu đồ nhiệt độ',
                fontSize: 20,
                fontColor: '#fff'
              },
              scales: {
                yAxes: [{ ticks: { min: 0, max: 45 } }],
              }
            }
          });
          new Chart("myChart2", {
            type: "line",
            data: {
              labels: x1Values,
              datasets: [{
                fill: false,
                lineTension: 0,
                backgroundColor: "rgba(0,0,255,1.0)",
                borderColor: "#ED9D00",
                data: y1Values
              }]
            },
            options: {
              legend: { display: false },
              title: {
                display: true,
                text: 'Biểu đồ độ ẩm',
                fontSize: 20,
                fontColor: '#fff'
              },
              scales: {
                yAxes: [{ ticks: { min: 0, max: 100 } }],
              }
            }
          });
        })
        .catch(error => console.log('error', error));
    }


    // Lấy lời khuyên từ API 
    function getAdvice() {
      var requestOptions = {
        method: 'GET',
      };
      fetch("https://sensor.herokuapp.com/loikhuyen", requestOptions)
        .then(response => response.text())
        .then(result => {
          var data = JSON.parse(result);
          console.log(data);
          document.getElementById("advice").innerHTML = data.mess;
        })
        .catch(error => console.log('error', error));
    }


    //-----------Hàm khởi tạo đối tượng request----------------
    function create_obj() {
      td = navigator.appName;
      if (td == "Microsoft Internet Explorer") {
        obj = new ActiveXObject("Microsoft.XMLHTTP");
      } else {
        obj = new XMLHttpRequest();
      }
      return obj;
    }
    //------------Khởi tạo biến toàn cục-----------------------------
    var xhttp = create_obj();//Đối tượng request cho setup wifi
    var xhttp_statusD = create_obj();//Đối tượng request cho cập nhật trạng thái
    var d1, d2, d3, d4;
    var ledconnect = 1;
    //===================Khởi tạo ban đầu khi load trang=============
    window.onload = function () {
      document.getElementById("homecontrol").style.display = "block";
      document.getElementById("wifisetup").style.display = "none";
      getIPconnect();//Gửi yêu cầu lấy IP kết nối
      getstatusD();//Gửi yêu cầu lấy trạng thái các chân điều khiển
      getDataAPI();//Gửi yêu cầu lấy dữ liệu nhiệt độ độ ẩm
      getAdvice();//Gửi yêu cầu lấy lời khuyên
    }
    //===================IPconnect====================================
    //--------Tạo request lấy địa chỉ IP kết nối----------------------
    function getIPconnect() {
      xhttp.open("GET", "/getIP", true);
      xhttp.onreadystatechange = process_ip;//nhận reponse 
      xhttp.send();
    }
    //-----------Kiểm tra response IP và hiển thị------------------
    function process_ip() {
      if (xhttp.readyState == 4 && xhttp.status == 200) {
        //------Updat data sử dụng javascript----------
        ketqua = xhttp.responseText;
        document.getElementById("ipconnected").innerHTML = ketqua;
      }
    }
    //===========Cập nhật trạng thái Led===============================
    //-----------Gửi yêu cầu lấy trạng thái các chân D-----------------
    function getstatusD() {
      xhttp_statusD.open("GET", "/getSTATUSD", true);
      xhttp_statusD.onreadystatechange = process_statusD;
      xhttp_statusD.send();
    }
    //-----------Gửi yêu cầu lấy dữ liệu nhiệt độ độ ẩm---------------
    function getDHTData() {
      getnhietdo();
      getdoam();
      getquangtro();
    }
    // Anh sang

    function getquangtro() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          document.getElementById("anhsangs").innerHTML = this.responseText;
        }
      };
      xhttp.open("GET", "docquangtro", true);
      xhttp.send();
    }

    //-----------Gửi yêu cầu lấy nhiệt độ---------------------------
    function getnhietdo() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          document.getElementById("nhietdos").innerHTML = this.responseText;
        }
      };
      xhttp.open("GET", "docnhietdo", true);
      xhttp.send();
    }
    //-----------Gửi yêu cầu lấy độ ẩm-------------------------------
    function getdoam() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          document.getElementById("doams").innerHTML = this.responseText;
        }
      };
      xhttp.open("GET", "docdoam", true);
      xhttp.send();
    }
    //
    function senDataToServer() {
      var doam = document.getElementById("doams").innerHTML;
      var nhietdo = document.getElementById("nhietdos").innerHTML;
      var url = `https://sensor.herokuapp.com/sensor/?temp=${nhietdo}&hum=${doam}`;
      fetch(url)
        .then(response => response.json())
        .then(data => console.log(data));
    }
    //-----------Kiểm tra và nhận response EEPROM----------------------
    function process_statusD() {
      if (xhttp_statusD.readyState == 4 && xhttp_statusD.status == 200) {
        if (ledconnect == 1) {
          ledconnect = 0;
          document.getElementById("ledconnect").style.background = "#222222";
        } else {
          ledconnect = 1;
          document.getElementById("ledconnect").style.background = "#00EE00";
        }
        //------Update trạng thái led tín hiệu lên panel điều khiển----
        var statusD = xhttp_statusD.responseText;
        var obj = JSON.parse(statusD);
        d1 = obj.D1;
        d2 = obj.D2;
        d3 = obj.D3;
        d4 = obj.D4;
        updateLedstatus(d1, d2, d3, d4);
      }
    }
    //----------Hiển thị trạng thái Led lên trình duyệt---------------------
    function updateLedstatus(D1, D2, D3, D4) {
      if (D1 == "1") {

        document.getElementById("ledstatus1").value = "OFF";
        document.getElementById("ledstatus1").style.background = "#222222";
      } else {
        document.getElementById("ledstatus1").value = "ON";
        document.getElementById("ledstatus1").style.background = "#23C48E";
      }
      if (D2 == "1") {
        document.getElementById("thietbi1").checked = false;
        document.getElementById("ledstatus2").value = "OFF";
        document.getElementById("ledstatus2").style.background = "#222222";
      } else {
        document.getElementById("thietbi1").checked = true;
        document.getElementById("ledstatus2").value = "ON";
        document.getElementById("ledstatus2").style.background = "#ED9D00";
      }
      if (D3 == "1") {
        document.getElementById("thietbi2").checked = false;
        document.getElementById("ledstatus3").value = "OFF";
        document.getElementById("ledstatus3").style.background = "#222222";
      } else {
        document.getElementById("thietbi2").checked = true;
        document.getElementById("ledstatus3").value = "ON";
        document.getElementById("ledstatus3").style.background = "#5F7CD8";
      }
      if (D4 == "1") {
        document.getElementById("thietbi3").checked = false;
        document.getElementById("ledstatus4").value = "OFF";
        document.getElementById("ledstatus4").style.background = "#222222";
      } else {
        document.getElementById("thietbi3").checked = true;
        document.getElementById("ledstatus4").value = "ON";
        document.getElementById("ledstatus4").style.background = "#03C0F8";
      }
    }
    //===========Tạo và gửi request khi ấn button============================
    //-----------Thiết lập dữ liệu và gửi request ON/OFF D4---
    function getbutton(n) {
      switch (n) {
        case 1:
          var ledstatus1 = document.getElementById("ledstatus1").value;
          if (ledstatus1 == "ON") {
            xhttp_statusD.open("GET", "/D1off", true);
          } else {
            xhttp_statusD.open("GET", "/D1on", true);
          }
          xhttp_statusD.onreadystatechange = process_statusD;
          xhttp_statusD.send();
          break;
        case 2:
          var ledstatus2 = document.getElementById("ledstatus2").value;
          if (ledstatus2 == "ON") {
            xhttp_statusD.open("GET", "/D2off", true);
          } else {
            xhttp_statusD.open("GET", "/D2on", true);
          }
          xhttp_statusD.onreadystatechange = process_statusD;
          xhttp_statusD.send();
          break;
        case 3:
          var ledstatus3 = document.getElementById("ledstatus3").value;
          if (ledstatus3 == "ON") {
            xhttp_statusD.open("GET", "/D3off", true);
          } else {
            xhttp_statusD.open("GET", "/D3on", true);
          }
          xhttp_statusD.onreadystatechange = process_statusD;
          xhttp_statusD.send();
          break;
        case 4:
          var ledstatus4 = document.getElementById("ledstatus4").value;
          if (ledstatus4 == "ON") {
            xhttp_statusD.open("GET", "/D4off", true);
          } else {
            xhttp_statusD.open("GET", "/D4on", true);
          }
          xhttp_statusD.onreadystatechange = process_statusD;
          xhttp_statusD.send();
          break;
      }
    }
    function getbuttonall(m) {
      if (m == "on") {
        xhttp_statusD.open("GET", "/Allon", true);
      } else if (m == "off") {
        xhttp_statusD.open("GET", "/Alloff", true);
      }
      xhttp_statusD.onreadystatechange = process_statusD;
      xhttp_statusD.send();
    }
    //===========Configure WiFi=====================================
    function configurewifi() {
      document.getElementById("homecontrol").style.display = "none";
      document.getElementById("wifisetup").style.display = "block";
    }
    //-----------Thiết lập dữ liệu và gửi request ssid và password---
    function writeEEPROM() {
      if (Empty(document.getElementById("ssid"), "Please enter ssid!") && Empty(document.getElementById("pass"), "Please enter password")) {
        var ssid = document.getElementById("ssid").value;
        var pass = document.getElementById("pass").value;
        xhttp.open("GET", "/writeEEPROM?ssid=" + ssid + "&pass=" + pass, true);
        xhttp.onreadystatechange = process;//nhận reponse 
        xhttp.send();
      }
    }
    function clearEEPROM() {
      if (confirm("Do you want to delete all saved wifi configurations?")) {
        xhttp.open("GET", "/clearEEPROM", true);
        xhttp.onreadystatechange = process;//nhận reponse 
        xhttp.send();
      }
    }
    function restartESP() {
      if (confirm("Do you want to reboot the device?")) {
        xhttp.open("GET", "/restartESP", true);
        xhttp.send();
        alert("Device is restarting! If no wifi is found please press reset!");
      }
    }
    //-----------Kiểm tra response -------------------------------------------
    function process() {
      if (xhttp.readyState == 4 && xhttp.status == 200) {
        //------Updat data sử dụng javascript----------
        ketqua = xhttp.responseText;
        document.getElementById("reponsetext").innerHTML = ketqua;
      }
    }
    //============Hàm thực hiện chứ năng khác================================
    //--------Cập nhật trạng thái tự động sau 2000 giây----------------------
    setInterval(function () {
      getstatusD();
      getDHTData();//Gửi yêu cầu lấy dữ liệu nhiệt độ và độ ẩm
    }, 5000);

    setInterval(function () {
      senDataToServer(); //Gửi dữ liệu nhiệt độ và độ ẩm lên server
      getDataAPI(); //Lấy dữ liệu từ server
      getAdvice()
    }, 60000);
    //--------Load lại trang để quay về Home control-------------------------
    function backHOME() {
      window.onload();
    }
    //----------------------------CHECK EMPTY--------------------------------
    function Empty(element, AlertMessage) {
      if (element.value.trim() == "") {
        alert(AlertMessage);
        element.focus();
        return false;
      } else {
        return true;
      }
    }
       //------------------------------------------------------------------------
  </script>
</body>

</html>
)=====";