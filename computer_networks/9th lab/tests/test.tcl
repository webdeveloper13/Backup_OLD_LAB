set ns [new Simulator]

$ns color 1 Red
$ns color 2 Blue

set nf [open out.nam w]
$ns namtrace-all $nf

set f [open simple4.tr w]
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
set n2 [$ns node]

$ns duplex-link $n0 $n1 1Mb 50ms DropTail
$ns duplex-link $n1 $n2 100Kb 5ms DropTail

$ns queue-limit $n1 $n2 10

$ns duplex-link-op $n0 $n1 orient right
$ns duplex-link-op $n1 $n2 orient right

$ns duplex-link-op $n1 $n2 queuePos 0.5

set udp [new Agent/UDP]
$ns attach-agent $n0 $udp

set null [new Agent/Null]
$ns attach-agent $n2 $null
$ns connect $udp $null
$udp set fid_ 1

set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set type_ UDP
$cbr set packet_size_ 100
$cbr set rate_ 160kb
$cbr set random_ false

$ns at 1 "$cbr start"
$ns at 11 "$cbr stop"

$ns at 12 "finish"

puts "CBR PACKET SIZE = [$cbr set packet_size_]"

$ns run
