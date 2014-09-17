// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h>
 
Servo flh,frh,rrh,rlh; 
Servo fll,frl,rrl,rll;

// set variables needed for some tasks

/*
frh = front right hip
 frl = front right leg
 flh = front left hip
 fll = front left leg
 rlh = rear left hip
 rll = rear left leg
 rrh = rear right hip
 rrl = rear right leg
 eye = sevor for sensor
 */

//set logical values for physical home position (cheap Chinese servos are cheap!)
int home_frh = 90; // front right hip
int home_flh = 90; //front left hip
int home_rlh = 80; // rear left hip
int home_rrh = 100; // rear right hip

int home_frl = 90; // front right leg
int home_fll = 95; // front left leg
int home_rrl = 90; // rear right leg
int home_rll = 100; // rear left leg



int b;
int x;
int w;
int up;
int up2;
int up3;
int down;
int down2;
int steps;
int rightsteps;
int leftsteps;
int back;
int pos;


 
void setup() 
{ 

  
   // assign servos to pins and center servos
  frh.attach(3);
  frh.write(home_frh);
  
  frl.attach(8);
  frl.write(home_frl);
  
  flh.attach(4);
  flh.write(home_flh);
  
  fll.attach(9);
  fll.write(home_fll);
  
  rlh.attach(5);
  rlh.write(home_rlh);
  
  rll.attach(10);
  rll.write(home_rll);
  
  rrh.attach(6);
  rrh.write(home_rrh);
  
  rrl.attach(11);
  rrl.write(home_rrl);
  
  
  
} 
 
 
void loop() 
{ 

forward();

} 



void forward()
{
  
  


  frl.write(home_frl+40);
  frh.write(home_frh-60);
  idle();
  
  rll.write(home_rll+40);
  rlh.write(home_rlh+40);
  idle();
  
  frl.write(home_frl);
  idle();
  rll.write(home_rll);
  idle();
  
  idle();

  frh.write(home_frh);
  idle();
  rlh.write(home_rlh);
  idle();
  
  
  
  
  fll.write(home_fll-40);
  flh.write(home_flh+60);
  idle();
  
  rrl.write(home_rrl-4);
  rrh.write(home_rrh-40);
  idle();
  
  fll.write(home_fll);
  idle();
  rrl.write(home_rrl);
  idle();
  
  idle();
  
  flh.write(home_flh);
  idle();
  rrh.write(home_rrh);
  idle();
  
}


void backward()
{

  rll.write(home_frl-30);
  rlh.write(home_frh-60);
  idle();
  
  frl.write(home_rll-30);
  frh.write(home_rlh+40);
  idle();
  
  rll.write(home_frl);
  idle();
  frl.write(home_rll);
  idle();
  
  idle();

  rlh.write(home_frh);
  idle();
  frh.write(home_rlh);
  idle();
  
  
  
  
  rrl.write(home_fll-30);
  rrh.write(home_flh+60);
  idle();
  
  fll.write(home_rrl-30);
  flh.write(home_rrh-40);
  idle();
  
  rrl.write(home_fll);
  idle();
  fll.write(home_rrl);
  idle();
  
  idle();
  
  rrh.write(home_flh);
  idle();
  flh.write(home_rrh);
  idle();
  
}


//////////////////////////////////////

void sayhi()
{
rrl.write(20);
rll.write(150);
idle();
flh.write(130);
fll.write(70);
idle();
frl.write(180);

for(int i=0;i<=2;i++)
{
  for(int j=90;j>=40;j--)
  {
   frh.write(j);
   delay(3);
  }
  
  for(int k=40;k<=120;k++)
  {
   frh.write(k);
   delay(3);
  }
  
  for(int l=120;l>=90;l--)
  {
   frh.write(l);
   delay(3);  
  }
}

frh.write(40);

}


void idle() // this is the delay between the steps -> walking speed
{
  delay(50);  // if set to a bigger number (more delay between the steps -> slower walking) you will see the walking pattern more clearly
}



void sleep()
{

  //hips
  frh.write(home_frh);
  flh.write(home_flh);
  rrh.write(home_rrh);
  rlh.write(home_rlh);
  
  // legs
  frl.write(home_frl + 70);
  fll.write(home_fll - 70);
  rll.write(home_rll - 70);
  rrl.write(home_rrl + 70);

}
//////////////////////////////////////
void stand()
{
  //hips
  frh.write(home_frh);
  flh.write(home_flh);
  rrh.write(home_rrh);
  rlh.write(home_rlh);
  
  //legs
  frl.write(home_frl);
  fll.write(home_fll);
  rll.write(home_rll);
  rrl.write(home_rrl);
}


