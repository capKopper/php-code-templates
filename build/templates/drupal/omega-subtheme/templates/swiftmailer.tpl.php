<?php
/**
 * @file
 * The default template file for e-mails.
 *
 * Available variables:
 * - $key: The key which identifies the e-mail. This is the $key provided to
 *   drupal_mail() which identifies the e-mail.
 * - $to: The recipient's e-mail address.
 * - $from: The sender's e-mail address.
 * - $language: The language used to compose the e-mail.
 * - $params: An array of parameters. This is the $params optionally provided to
 *   drupal_mail().
 * - $subject: The subject.
 * - $body: The actual content.
 *
 * Extra variables (provided by capKopper SMTP module):
 * - $logo: A full image element.
 */
?>
<div>
  <table width="100%" cellpadding="0" cellspacing="0">
    <thead>
      <tr>
        <th colspan="3"><?php print $logo; ?></th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td>
          <div class="main"><?php print $body; ?></div>
        </td>
      </tr>
    </tbody>
    <tfoot>
      <tr>
        <th colspan="3">&nbsp;
        </th>
      </tr>
    </tfoot>
  </table>
</div>
