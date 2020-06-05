set ns [new Simulator]

$ns color 1 Red

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

$ns duplex-link-op $n0 $n1 orient right

set udp [new Agent/UDP]
$ns attach-agent $n0 $udp

set null [new Agent/Null]
$ns attach-agent $n1 $null
$ns connect $udp $null
$udp set fid_ 1

set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set type_ CBR
$cbr set packet_size 1000
$cbr set interval_ 0.010
$cbr set random_ false

$ns at 1 "$cbr start"
$ns at 10 "$cbr stop"

$ns at 11 "finish"

puts "CBR Packet size = [$cbr set packet_size]"
puts "CBR interval = [$cbr set interval_]"

$ns run