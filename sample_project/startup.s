.import main
.export init, exit

.segment "STARTUP"

init:
    CLD
    JSR main

exit:
    BRK