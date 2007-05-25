<?php
/* SVN FILE: $Id: javascript.test.php,v 1.1 2007-05-25 05:54:26 rflint%ryanflint.com Exp $ */
/**
 * Short description for file.
 *
 * Long description for file
 *
 * PHP versions 4 and 5
 *
 * CakePHP Test Suite <https://trac.cakephp.org/wiki/Developement/TestSuite>
 * Copyright (c) 2006, Larry E. Masters Shorewood, IL. 60431
 * Author(s): Larry E. Masters aka PhpNut <phpnut@gmail.com>
 *
 *  Licensed under The Open Group Test Suite License
 *  Redistributions of files must retain the above copyright notice.
 *
 * @filesource
 * @author       Larry E. Masters aka PhpNut <phpnut@gmail.com>
 * @copyright    Copyright (c) 2006, Larry E. Masters Shorewood, IL. 60431
 * @link         http://www.phpnut.com/projects/
 * @package      test_suite
 * @subpackage   test_suite.cases.app
 * @since        CakePHP Test Suite v 1.0.0.0
 * @version      $Revision: 1.1 $
 * @modifiedby   $LastChangedBy: phpnut $
 * @lastmodified $Date: 2007-05-25 05:54:26 $
 * @license      http://www.opensource.org/licenses/opengroup.php The Open Group Test Suite License
 */
	require_once LIBS.'../app_helper.php';
	require_once LIBS.DS.'view'.DS.'helper.php';
	require_once LIBS.DS.'view'.DS.'helpers'.DS.'html.php';
	require_once LIBS.DS.'view'.DS.'helpers'.DS.'form.php';
	require_once LIBS.DS.'view'.DS.'helpers'.DS.'javascript.php';
/**
 * Short description for class.
 *
 * @package    test_suite
 * @subpackage test_suite.cases.libs
 * @since      CakePHP Test Suite v 1.0.0.0
 */
class JavascriptTest extends UnitTestCase {

	function setUp() {
		$this->js = new JavascriptHelper();
		$this->js->Html = new HtmlHelper();
		$this->js->Form = new FormHelper();
	}

	function testLink() {
		$result = $this->js->link('script.js');
		$expected = '<script type="text/javascript" src="js/script.js"></script>';
		$this->assertEqual($result, $expected);
		
		$result = $this->js->link('script');
		$expected = '<script type="text/javascript" src="js/script.js"></script>';
		$this->assertEqual($result, $expected);
		
		$result = $this->js->link('scriptaculous.js?load=effects');
		$expected = '<script type="text/javascript" src="js/scriptaculous.js?load=effects"></script>';
		$this->assertEqual($result, $expected);
		
		$result = $this->js->link('jquery-1.1.2');
		$expected = '<script type="text/javascript" src="js/jquery-1.1.2.js"></script>';
		$this->assertEqual($result, $expected);
	}
	
	function testObjectGeneration() {
		$object = array('title' => 'New thing', 'indexes' => array(5, 6, 7, 8));

		$result = $this->js->object($object);
		$expected = '{"title":"New thing", "indexes":[5, 6, 7, 8]}';
		$this->assertEqual($result, $expected);

		$result = $this->js->object(array('default' => 0));
		$expected = '{"default":0}';
		$this->assertEqual($result, $expected);
		
		$result = $this->js->object(array(
			'2007' => array(
				'Spring'=>array('1'=>array('id'=>'1','name'=>'Josh'), '2'=>array('id'=>'2','name'=>'Becky')),
				'Fall' => array('1'=>array('id'=>'1','name'=>'Josh'), '2'=>array('id'=>'2','name'=>'Becky'))
			), '2006' => array(
				'Spring' => array('1'=>array('id'=>'1','name'=>'Josh'), '2'=>array('id'=>'2','name'=>'Becky')),
				'Fall' => array('1' => array('id'=>'1','name'=>'Josh'), '2'=>array('id'=>'2','name'=>'Becky') 
			))
		));
		$expected = '{"2007":{"Spring":{"1":{"id":1, "name":"Josh"}, "2":{"id":2, "name":"Becky"}}, "Fall":{"1":{"id":1, "name":"Josh"}, "2":{"id":2, "name":"Becky"}}}, "2006":{"Spring":{"1":{"id":1, "name":"Josh"}, "2":{"id":2, "name":"Becky"}}, "Fall":{"1":{"id":1, "name":"Josh"}, "2":{"id":2, "name":"Becky"}}}}';
		$this->assertEqual($result, $expected);
	}

	function tearDown() {
		unset($this->js);
	}
}

?>