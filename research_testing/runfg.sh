#!/bin/zsh

cd /Applications/FlightGear.app/Contents/Resources

export FG_ROOT=/Applications/FlightGear.app

./../MacOS/fgfs --fdm=null --native-fdm=socket,in,30,localhost,5502,udp  --enable-terrasync  --aircraft=c172p --fog-fastest --disable-clouds --start-date-lat=2004:06:01:09:00:00 --disable-sound --in-air --airport=EDDH --runway= --altitude=7224 --heading=113 --offset-distance=4.72 --offset-azimuth=0   &
