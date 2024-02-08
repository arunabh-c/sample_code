
# Hashed Page Table

![Hashed Page Table](hashed_page_table.png)

## Definitions
In the diagram:

Virtual Page Number (VPN): `p`, `q`
Page Frame Number (PFN): `r`
Offset: `d`
Hash Function: `h(x)`
Hashed Page Table with schema `(key, VPN, PFN, Pointer to next entry with key)` for each entry in the table
It so happens that `h(p) = same_key` and `h(q) = same_key`. There is hash collision. Both `p` and `q` are hashed to the `same_key`.

This is resolved by chaining the entry with `VPN = q` to the entry with `VPN = p`. Chaining means to use the `Pointer` field in the entry with `VPN = q` to **point** to the entry with `VPN = p`.

## Workflow
Operating system (OS) grabs `p` from the CPU, and performs `h(p)` to get `same_key`.

OS looks up the first entry in the Hashed Page Table with `key = same_key` and checks `p` against the first entry's `VPN` field. It checks `p` against `q`. This is incorrect.

OS uses the `Pointer` in the first entry to find the second entry. It knows that the second entry has the same `key = same_key`, because the Page Table is constructed this way. OS checks `p` against the seond entry's `VPN` field. It checks `p` against `p`. This is correct. Bam. Kill confirmed.

OS knows that this is the correct entry it is looking for. It grabs `PFN` from the second entry. It grabs `r`. `r` is the correct physical frame number that corresponds to virtual page number `p`.

OS uses `r` to look for the physical frame it wants in physical memory, and looks for the exact word wanted which is offset by `d` within frame `r` in physical memory. OS grabs the contents of the word and we're done.

Reference:
https://cs.stackexchange.com/questions/85207/explain-hashed-page-tables-in-operating-system
