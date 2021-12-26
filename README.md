<a href="https://github.com/404"><img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif" width="100%"></a>

<div align = "center">

# [Password Based Door Open System Using LPC2148](#)
  
</div>

<div align = "center">
	
<a href="https://github.com/404"><img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif" width="100%"></a>

## Table of Contents

</br>

| | Table Of Contents |
|--|----------------|
| 1 | [About](#About)  |
| 2 | [Setup](#Setup)  | 
| 3 | [Contributors](#Contributors) | 

</div>

<a href="https://github.com/404"><img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif" width="100%"></a>

<div align = "center">
	
## Directory Structure
	
</div>

```js
├── Source
│   ├── LPC2148.c
|
├── Report
│   ├── Report.pdf
│ 
└── README.md
```

<a href="https://github.com/404"><img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif" width="100%"></a>

<div align = "center">
	
## About
	
</div>

- Nowadays, many devices operations are based on digital technology like a token-based digital identity device. The objective of this project in its simplest terms is to replace metallic keys by building a fully featured password enabled electronic security system prototype. 
- One such device is Password Based Door Open System Using LPC2148. With this kind of entry system, people no longer have to worry about lost or stolen keys and they never have to bring keys with them everywhere they go or hide them in secret places to keep them away from the hands of unauthorized individuals. 
- The secret numbers of the keypad door locks can be easily changed into another combination. When people feel that their current number combinations have been divulged to unauthorized individuals, they can always change the codes anytime. 
- In addition, if the current owners of the house decide to sell the property or have the house rented to others, they can always just let the new people living there know about the access codes to the locks. There is no need to change locks at all. 
- The aim of this project therefore, is to design and construct a keypad/password based electronic door access key that will be able to,
  
  - Eliminate the use of mechanical/metallic keys.  
  - Prevent events of key misplacements. 
  - Avoid excessive key duplication for everyone in the house. 
  - Make the apartment where it is installed more difficult to break into.

<a href="https://github.com/404"><img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif" width="100%"></a>

<div align = "center">
	
## Working Principle
	
</div>

- At the lowest level, keyboards are organized in a matrix of rows and columns. 
- The CPU accesses both rows and columns through ports.
- When a key is pressed, a row and a column make a contact. otherwise, there is no connection between rows 
and columns. 
- The status of each key can be determined by a process called Scanning. 
- There are many methods depending on how you connect your keypad with your controller, but the basic 
logic is the same. 
- Let’s assume that all the column pins (Col1 – Col4) are connected to the input’s pins and all the row pins 
are connected to the output pins of the microcontroller.
- In the normal case, all the column pins are pulled up (HIGH state) by internal or external pull-up resistors. 
- Now we can read the status of each switch through scanning.
- A logic LOW is given to Row1 and others (Row2 – Row-4) HIGH. 
- Now each Column is scanned and if any switch belongs to the 1st row is pressed the corresponding column 
will pull down (logic LOW) and we can detect the pressed key. This process is repeated for all rows.
	
<a href="https://github.com/404"><img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif" width="100%"></a>

<div align = "center">
	
## Setup

Software Used : **Keil IDE**.
	
<a href="https://github.com/404"><img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif" width="100%"></a>
	
## Limitation & Scope
	
</div>

- This project would only feature a password-based electronic door access system. 
- In other words, it only incorporates the hexadecimal keypad only for authentication. 
- Other more advanced security features such as a fingerprint sensor, an iris scanner or a facial recognition 
camera would not be incorporated.

<a href="https://github.com/404"><img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif" width="100%"></a>

<div align = "center">
	
## Contributors
  
| [Harsha Sathish](https://github.com/hxrshx) | [Kanchi Durga Priyanka](https://in.linkedin.com/in/kanchi-durga-priyanka-3440311b8) | [Srija Tiyyagura](https://in.linkedin.com/in/srija-tiyyagura-62b8331b2) | [Arvind Kumar K](https://github.com/arvindkumar-prog) |
|----------------|----------------|----------------|----------------|

</div>

<a href="https://github.com/404"><img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif" width="100%"></a>
