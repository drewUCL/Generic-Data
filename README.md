Generic Data
========================

To allow a successful trading system to be built one must structure their data. This project provides a generic Data class to help you upload your stock data. The class works off Google finance data although be sure to convert your timestamp in the csv you download to a unix timestamp as often used in algorithmic trading backtesters. To do this in excel simply convert using this formula: **=(A2 - DATE(1970,1,1))*86400**.

Feel free to change the data structure as your needs require. Currently the system will write data to memory in the following format: 

<br/>

[1] Unix datetime <br/>
[2] Open <br/>
[3] High <br/>
[4] Low <br/>
[5] Close <br/>
[6] Volume <br/>