# Lab - Finding Anagrams

The directory for this lab is `tux:/home/kschmidt/public_html/CS265/Labs/Anagram`

In this lab, you'll write a program to find the most common anagrams in our machine's built-in dictionary, `/usr/share/dict/words`. All of the tools (except one) will be provided for you; your job is combine them in a single Bash script using pipes and/or redirects.

The purpose of this lab is to show how the UNIX philosophy of combining simple programs with pipes can solve interesting problems.

## Problem

Two words are anagrams if one can be obtained from the other by permuting the letters. For example, the words "stop" and "pots" are anagrams since the letters "s", "t", "o", and "p" in "stop" can be rearranged to obtain the word "pots".

Given the machine's built-in dictionary, `/usr/share/dict/words`, we would like to output the **10 most frequent anagram classes**. For example, if `/usr/share/dict/words` only contained these words - 

```
hat
at
flat
snap
yap
pay
what
meat
cat
paper
team
lager
rat
tar
large
tame
```

- we'd want our script to output:

```
1 cat
1 flat
1 hat
1 paper
1 snap
1 what
2 lager large
2 rat tar
2 yap pay
3 meat tame team
```

## Tools

The following programs are available for you to use (except one, which you'll have to write yourself). You may also use any other Unix utilities. Your task is to combine these tools in a single Bash script using pipes and/or redirects.

1) A C program called `sign.c`. `sign.c` reads a file of words from stdin. For every word, it'll print to stdout the word sorted by letters, followed by a space, followed by the original word.

For example, if the file `temp` contained these contents -

```
cat
pat
attack
tap
```

- then running `cat temp | ./sign` should output:

```
act cat
apt pat
aacktt attack
apt tap
```

You'll need to compile `sign.c` into an executable to run it. You can do this by running the C compiler `gcc`. By default, `gcc` creates an executable named `a.out`. If you want to provide a different output filename, you can use the `-o` flag (see the gcc manpage for more details).

2) The `sort` utility, which sorts its input. Remember that you can also sort numerically by using the `-n` flag.

3) An awk program called `squash.awk`, which will put all **adjacent** lines with the same first field onto the same line, space separated. For example, given the file `temp` with these contents -

```
aacktt attack
act cat
apt pat
apt tap
```

- running `awk -f squash.awk temp` will output:

```
attack
cat
pat tap
```

4) **You must write** an awk program that counts the number of space-separated words on a line. For example, given this input - 

```
rat
tap pat
glare lager large regal
leap pale peal
meat tame team
```

- your awk program should output:

```
1 rat
2 tap pat
4 glare lager large regal
3 leap pale peal
3 meat tame team
```

5) The `head`/`tail` utilities, which print the first/last `n` lines of their input.

## Solution

Your submission must include **a Bash script named `anagram`**. Your script must combine all of the preceeding tools with pipes to output the **10 most frequent anagram classes in `/usr/share/dict/words`**.

We will run your Bash script without an interpreter, so make sure your sha-bangs are set properly.

Your script must include a command to compile `sign.c`. **`sign.c` will not be compiled for you.**

## Submission

You must submit these files (and _only_ these files):

- `anagram`: Your Bash script.
- Any other script files used by `anagram` (**including** `sign.c` and `squash.awk`). **Don't include the dictionary file**, `/usr/share/dict/words`.
- `README`: This file is optional. If there's anything we should know before we grade your submission, put it in here.
