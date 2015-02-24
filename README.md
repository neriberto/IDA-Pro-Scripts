DA Pro Scripts
===============

Some IDA scripts to assist with reverse engineering

To install the scripts with all submodules try:

```
git clone --recursive https://github.com/neriberto/IDA-Pro-Scripts.git
```

IDA Python Scripts
------------------

* functions_md5.py - Enumerate all functions and print the MD5 hash.
* strings_base64decode.py - Find for base64 encoded strings.
* strings_suspicious.py - Uses brute force to find xored strings (I wrote it based on [xor viper module](https://github.com/neriberto/viper/blob/master/modules/xor.py).

Submodules (included)
---------------------

* [reversing](https://github.com/arbor/reversing) from [Arbor Networks](https://github.com/arbor)
* [func-renamer](https://bitbucket.org/Alexander_Hanel/func-renamer) from [Alexander Hanel](http://hooked-on-mnemonics.blogspot.com)

Another IDA Pro Addons (not included)
-------------------------------------

The list above are not include in this repository as submodule

* [android-scripts](https://github.com/strazzere/android-scripts) from [Tim Strazzere](https://github.com/strazzere)
* [malware-analysis](https://github.com/SpiderLabs/malware-analysis) from [SpiderLabs](https://github.com/SpiderLabs)
* [Reversing](https://github.com/mandiant/Reversing) from [Madiant](https://github.com/mandiant)
* [flare-ida](https://github.com/fireeye/flare-ida) from [FireEye Labs](https://github.com/fireeye)
* [ida-efiutils](https://github.com/snare/ida-efiutils) from [snare](https://github.com/snare)

Ideas to implement
------------------

The [FireInsight-plugin](https://github.com/nmantani/FileInsight-plugins) has many cool plugins for FileInsight.
