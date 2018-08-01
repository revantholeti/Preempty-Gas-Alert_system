# Preempty-Gas-Alert_system
Get a Alert message that your gas is going to empty.

# Why
In house anyone don't know when the GAS-CYLINDER is going to empty. If it is not working then food cannot be prepared. So to make this not
happen I developed a project in which owner of the cylinder gets a warning message. By that owner can prebook the cylinder before its gonna
empty.

# Requirments
1. Aurdino
2. GSM module
3. Weight Sensor

# Process 
Aurdino code is diployed in the aurdino chip and when it is powered the code present in that chip is executed. GSM module is connected to it
so that a SIM is inserted. A weight sensor with HX711 chip is conneted with aurdino to measure weight of the cylinder. 
Weight sensor is kept under cylinder and aurdino is powered. Promgram written is running and weight of cylinder is taken for every 3 seconds.
If weight is less than 2Kgs then aurdino powers up the GSM and sms is sent to the owners number that was already provided in the program written.
