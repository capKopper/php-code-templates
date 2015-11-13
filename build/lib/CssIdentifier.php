<?php
require_once "phing/Task.php";

class CssIdentifier extends Task
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

        // @see drupal_clean_css_identifier().
        $identifier = strtr($this->string, array(' ' => '-', '_' => '-', '/' => '-', '[' => '-', ']' => ''));

        // Valid characters in a CSS identifier are:
        // - the hyphen (U+002D)
        // - a-z (U+0030 - U+0039)
        // - A-Z (U+0041 - U+005A)
        // - the underscore (U+005F)
        // - 0-9 (U+0061 - U+007A)
        // - ISO 10646 characters U+00A1 and higher
        // We strip out any character not in the above list.
        $identifier = preg_replace('/[^\x{002D}\x{0030}-\x{0039}\x{0041}-\x{005A}\x{005F}\x{0061}-\x{007A}\x{00A1}-\x{FFFF}]/u', '', $identifier);

        $this->getProject()->setProperty($this->property, $identifier);
    }
}
