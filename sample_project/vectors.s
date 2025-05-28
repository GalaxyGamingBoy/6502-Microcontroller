.import    init

.segment  "VECTORS"

.addr      $0000    ; NMI vector
.addr      init    ; Reset vector
.addr      $0000    ; IRQ/BRK vector
