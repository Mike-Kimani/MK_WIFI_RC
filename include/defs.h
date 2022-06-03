
//onboard led
#define blueonboard 2

//Motor driver connections
#define in1 18
#define in2 19
#define ena 5

//Accelerator and decelerator buttons
#define accelerator 32
#define decelerator 33

//Accelerator and decelerator
int accelerator_state = 0;
int decelerator_state = 0;
int emergency_state = 0;

//Servo pin
#define servopin 23

//Steering buttons
#define rightsteer 25
#define leftsteer 26
#define centresteer 27

//Steering button states
int rightstate;
int leftstate;
int centerstate;


//wifi credentials
const char* ssid = "mkwifi";
const char* password = "mkcart99";

//client times
uint64_t currentime;
uint64_t prevtime;
int timeoutTime;