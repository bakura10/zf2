<?php
/*
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * This software consists of voluntary contributions made by many individuals
 * and is licensed under the MIT license.
 */

namespace Bench;

use Athletic\AthleticEvent;
use Zend\EventManager\Event;

class EventManagerBenchmark extends AthleticEvent
{
    /**
     * @var \Zend\EventManager\EventManager
     */
    private $eventManager;

    public function setUp()
    {
        $this->eventManager = new \Zend\EventManager\EventManager();
    }

    /**
     * @iterations 1000
     */
    public function attach10Listeners()
    {
        $this->eventManager->attach('foo', function() {}, 5);
        $this->eventManager->trigger('foo', new Event());
        /*$this->eventManager->attach('*', function() {});
        $this->eventManager->detach('*');
        $this->eventManager->attach('*', function() {});
        $this->eventManager->attach('*', function() {});
        $this->eventManager->attach('bar', function() {});

        for ($i = 0 ; $i != 15 ; ++$i) {
            $this->eventManager->attach('bar' . $i, function() {}, $i);
        }

        $this->eventManager->trigger('foo', new Event());
        $this->eventManager->trigger('foo', new Event());
        $this->eventManager->trigger('bar', new Event());
        $this->eventManager->trigger('bar1', new Event());
        $this->eventManager->trigger('bar2', new Event());*/
    }
}