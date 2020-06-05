set ns [new Simulator]

$ns color 1 Red
$ns color 2 Blue

set nf [open out.nam w]
$ns namtrace-all $nf

set f [open simple.tr w]
$ns trace-all $f

proc finish {} {
	global ns nf f
	$ns flush-trace
	close $nf
	close $f
	exec nam out.nam &
	exit 0
}

set n0 [$ns node]
set n1 [$ns node]

$ns duplex-link $n0 $n1 10Mb 10ms DropTail

#$ns queue-limit $n0 $n1 10

$ns duplex-link-op $n0 $n1 orient right

#$ns duplex-link-op $n0 $n1 queuePos 0.5

set tcp [new Agent/TCP]
$ns attach-agent $n0 $tcp
$tcp set class_ 2

set sink [new Agent/TCPSink]
$ns attach-agent $n1 $sink
$ns connect $tcp $sink
$tcp set fid_ 1

set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP

$ns at 1.0 "$ftp start"
$ns at 4.0 "$ftp stop"

$ns at 5.0 "finish"

$ns run
