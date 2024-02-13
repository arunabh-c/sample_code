The entire page table was kept in the main memory to overcome this size issue. but the problem here is two main memory references are required: 
1. To find the frame number 
2. To go to the address specified by frame number 
To overcome this problem a high-speed cache is set up for page table entries called a Translation Lookaside Buffer (TLB). Translation Lookaside Buffer (TLB) is a special cache used to keep track of recently used transactions.

TLB first checks if the page is already in main memory, if not in main memory a page fault is issued then the TLB is updated to include the new page entry.

## Steps in TLB hit
1. CPU generates a virtual (logical) address. 
2. It is checked in TLB (present). 
3. The corresponding frame number is retrieved, which now tells where the main memory page lies. 

## Steps in TLB miss
1. CPU generates a virtual (logical) address. 
2. It is checked in TLB (not present). 
3. Now the page number is matched to the page table residing in the main memory (assuming the page table contains all PTE). 
4. The corresponding frame number is retrieved, which now tells where the main memory page lies. 
5. The TLB is updated with new PTE (if space is not there, one of the replacement techniques comes into the picture i.e either FIFO, LRU or MFU etc).

## Effective memory access time(EMAT)
 TLB is used to reduce adequate memory access time as it is a high-speed associative cache. 

EMAT = h*(c+m) + (1-h)*(c+2m) 
where, h = hit ratio of TLB 
m = Memory access time 
c = TLB access time 

References: https://www.geeksforgeeks.org/translation-lookaside-buffer-tlb-in-paging/
