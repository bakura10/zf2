<?php

require_once __DIR__ . '/../vendor/autoload.php';

$nb_occur=1000;

$time_start = microtime(true);

$eventManager  = new \Zend\EventManager\EventManager(array('myid'));
$sharedManager = new \Zend\EventManager\SharedEventManager();

$eventManager->setSharedManager($sharedManager);
$listener  = $eventManager->attach('event', function() { echo 'hello'; });
//$sharedManager->attach('myid', 'event', function() { echo 'world'; }, -1);

//$eventManager->trigger('event');

$eventManager->detach($listener);

var_dump($eventManager);

/*for ($i = 0 ; $i != 50 ; ++$i) {
    $eventManager->attach('event', function() {}, $i);
    $sharedManager->attach('myid', 'event', function() {});
}

for ($i=0 ; $i<$nb_occur; $i++)
{
    $eventManager->trigger('event');
}*/

$time_end = microtime(true);
$time = $time_end - $time_start;

echo 'Durée : '.$time.' secondes<br/>';
echo 'Memoire' . memory_get_peak_usage();
