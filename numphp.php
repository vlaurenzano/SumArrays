<?php
$br = (php_sapi_name() == "cli")? "":"<br>";

if(!extension_loaded('numphp')) {
	dl('numphp.' . PHP_SHLIB_SUFFIX);
}
$module = 'numphp';
$functions = get_extension_funcs($module);
echo "Functions available in the test extension:$br\n";
foreach($functions as $func) {
    echo $func."$br\n";
}
echo "$br\n";
$function = 'confirm_' . $module . '_compiled';
if (extension_loaded($module)) {
	$str = $function($module);
} else {
	$str = "Module $module is not compiled into PHP";
}
echo "$str\n";


function php_sum_arrays($arrayOne, $arrayTwo){
	$sum = [];
	for($i = 0; $i < count($arrayOne); $i++){
		$sum[] = $arrayOne[$i] + $arrayTwo[$i];
	}
	return $sum;
}


$array = range(0,10000,1);

$arrayOne = array_flip($array);
$arrayTwo = array_flip($array);


shuffle($arrayOne);
shuffle($arrayTwo);

$cImpl = sum_arrays($arrayOne, $arrayTwo); 
$phpImpl = php_sum_arrays($arrayOne, $arrayTwo);

echo 'Pass: ', $cImpl == $phpImpl , "\n";

$iterations = 10;

$milliseconds = round(microtime(true) * 1000);
for($i = 0; $i < $iterations; $i++){
	$cImpl = sum_arrays($arrayOne, $arrayTwo); 
}
echo "\n", 'C implementation took: ', round(microtime(true) * 1000) - $milliseconds , ' milliseconds';


$milliseconds = round(microtime(true) * 1000);
for($i = 0; $i < $iterations; $i++){
	$cImpl = php_sum_arrays($arrayOne, $arrayTwo); 
}
echo "\n", 'PHP implementation took: ', round(microtime(true) * 1000) - $milliseconds , ' milliseconds';
echo "\n";



?>
