#create a simulator object
set ns [new Simulator]
#(i)open a file out.nam for writing and 
#(ii) tell the simulator object that we created above to write all simulation data that is going to be relevant for nam into this file
set nf [open out.nam w]
$ns nametrace-all $nf

#add a "finish" procedure that closes the trace file and starts nam
proc finish {} {
	global ns nf
	$ns flush-trace
	close $nf
	exec nam out.nam &
	exit 0
}
#a new object is created because of $ns node ,so here we have two nodes now..
set n0 [$ns node]
set n1 [$ns node]
#connect both the nodes
$ns duplex-link $n0 $n1 1Mb 10ms DropTail
#execute the finish procedure after 5 secs of simulation
$ns at 5.0 "finish"
#finally starts the simulation
$ns run