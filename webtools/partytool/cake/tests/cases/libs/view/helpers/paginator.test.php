<?php
/* SVN FILE: $Id: paginator.test.php,v 1.1 2007-05-25 05:54:26 rflint%ryanflint.com Exp $ */
/**
 * Short description for file.
 *
 * Long description for file
 *
 * PHP versions 4 and 5
 *
 * CakePHP(tm) Tests <https://trac.cakephp.org/wiki/Developement/TestSuite>
 * Copyright 2005-2007, Cake Software Foundation, Inc.
 *								1785 E. Sahara Avenue, Suite 490-204
 *								Las Vegas, Nevada 89104
 *
 *  Licensed under The Open Group Test Suite License
 *  Redistributions of files must retain the above copyright notice.
 *
 * @filesource
 * @copyright		Copyright 2005-2007, Cake Software Foundation, Inc.
 * @link				https://trac.cakephp.org/wiki/Developement/TestSuite CakePHP(tm) Tests
 * @package			cake.tests
 * @subpackage		cake.tests.cases.libs.view.helpers
 * @since			CakePHP(tm) v 1.2.0.4206
 * @version			$Revision: 1.1 $
 * @modifiedby		$LastChangedBy: phpnut $
 * @lastmodified	$Date: 2007-05-25 05:54:26 $
 * @license			http://www.opensource.org/licenses/opengroup.php The Open Group Test Suite License
 */
	require_once LIBS.'../app_helper.php';
	require_once LIBS.DS.'view'.DS.'helper.php';
	require_once LIBS.DS.'view'.DS.'helpers'.DS.'html.php';
	require_once LIBS.DS.'view'.DS.'helpers'.DS.'ajax.php';
	require_once LIBS.DS.'view'.DS.'helpers'.DS.'paginator.php';
/**
 * Short description for class.
 *
 * @package		cake.tests
 * @subpackage	cake.tests.cases.libs.view.helpers
 */
class PaginatorTest extends UnitTestCase {

	function setUp() {
		$this->paginator = new PaginatorHelper();
		$this->paginator->params['paging'] = array(
			'Article' => array(
				'current' => 9,
				'count' => 62,
				'prevPage' => false,
				'nextPage' => true,
				'pageCount' => 7,
				'defaults' => array(
					'order' => 'Article.date DESC',
					'limit' => 9,
					'conditions' => array()
                )
			),

			'options' => array(
				'order' => 'Article.date DESC',
				'limit' => 9,
				'page' => 1
			)
		);
	}

	function testHasPrevious() {
		$this->assertIdentical($this->paginator->hasPrev(), false);
		$this->paginator->params['paging']['Article']['prevPage'] = true;
		$this->assertIdentical($this->paginator->hasPrev(), true);
		$this->paginator->params['paging']['Article']['prevPage'] = false;
	}

	function testHasNext() {
		$this->assertIdentical($this->paginator->hasNext(), true);
		$this->paginator->params['paging']['Article']['nextPage'] = false;
		$this->assertIdentical($this->paginator->hasNext(), false);
		$this->paginator->params['paging']['Article']['nextPage'] = true;
	}

	function tearDown() {
		unset($this->paginator);
	}
}

?>