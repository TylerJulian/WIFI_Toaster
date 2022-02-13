# WIFI_Toaster
Hacklahoma 2022 repo for our wifi toaster project.

## Inspiration
 The wifi toaster was born from laziness. It was from a student's desire to not get up to toast bread. 

## What it does
The convenient app allows the user to load bread into the toaster and start it from anywhere with an internet connection. The toaster will notify you when the toast is done. The app loads the toaster starts the cooking process and notifies the user when the toast is done. Each control is can be triggered wirelessly from any distance. 

## How we built it
We 3dprinted a breadbox that doubles as a hopper. The breadbox is located above the toaster, and it has a secret. There is a trapdoor that releases the bread into the toaster at the push of the button on the android app. The trapdoor of the breadbox is controlled using a servo and ESP32 microcontroller. 

We 3d printed a rack and pinion to push the lever down on the toaster to begin the cooking process. The rack and pinion are powered by another servo that is controlled using another servo and the same ESP32 microcontroller. 

We are using an ultrasonic sensor to sense if the toast is done cooking. When the toast pops out of the toaster, the app displays a notification to the user to tell them their toast is done. 

The wifi toaster is entirely wireless. You can start cooking toast and not touch the machine during the entire process until the toast is done. We are using an ESP32 microcontroller to connect to a cloud service which the android app also connects to, so the two devices can communicate.

## Challenges we ran into
We encountered two major problems during the process of designing and building our hack. The first major problem was figuring out how to program and configure the ESP32 and get it to connect to the android app and the cloud service. We spent the first quarter of our time fixing connection issues.

The second problem was an issue with time and 3d printing. Normally you have the chance to iterate through multiple designs when you are 3d printing components. Prints were often 6+ hours long, and we had only 24 hours total to build everything, so we had to make our designs count and work on the first try or modify them after the print to get them working. Waiting on prints to finish was also another issue that we had encountered. We would have to find a way to make use of our time when we were blocked by not having the parts ready yet. 

## Accomplishments that we're proud of and What we learned
We are very proud that were able to overcome our issues with connecting to the internet, and most of the 3d printed parts worked the first try. We are very happy with our final design and we learned a good amount in the last 24 hours.

## What's next for Wifi toaster
The next step for the wifi toaster is to refine our design and improve our ideas. The autoloading hopper design is revolutionary and has never been done before. 
