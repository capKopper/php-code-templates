<?php
require_once "phing/Task.php";

class CamelCase extends Task
{
    protected $string = NULL;
    protected $property = NULL;

    public function setString($string)
    {
        $this->string = $string;
    }

    public function getString()
    {
        return $this->string ?: '';
    }

    /**
     * Set the string.
     *
     * @param string $str
     */
    public function setProperty($str) {
        $this->property = $str;
    }

    public function init()
    {
    }

    public function main()
    {
        if ($this->string === NULL) {
          throw new BuildException("string attribute is required.", $this->location);
        }

        if ($this->property === NULL) {
          throw new BuildException("property attribute is required.", $this->location);
        }

        $callback = function($match) {
          return strtoupper($match[1]);
        };

        $name = preg_replace_callback('/(?:^|_)(\w)/', $callback, strtolower($this->string));
        $this->getProject()->setProperty($this->property, $name);
    }
}
