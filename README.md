# SumArrays
This extension sums two 1d arrays in C. It is inspired by numpy and is equivalent to the following php code:

```
function php_sum_arrays($arrayOne, $arrayTwo){
	$sum = [];
	for($i = 0; $i < count($arrayOne); $i++){
		$sum[] = $arrayOne[$i] + $arrayTwo[$i];
	}
	return $sum;
}
```
It runs at 4 to 6 times the speed of the php code. 

#Installation

Not suitable for production but..

```
Make folder
CD into folder
git clone https://github.com/vlaurenzano/SumArrays.git 
phpize
sudo make install
add extension=numphp.so to your ini file





